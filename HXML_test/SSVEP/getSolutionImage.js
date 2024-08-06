function getSolImage(Input) {

    Inputs_temp=new Float32Array(Input.flat());

    let Inputs = new Float32Array(1000 * 60);
    // 使用 set 方法将 Input1 填入 sampledData 的前几位
    Inputs.set(Inputs_temp);

    // Assuming data is a Float32Array
    let inputs = new Float32Array(Inputs);
    let outputs = new Float32Array(20000); // Adjust size as needed

    // Move data to WASM heap
    let inputsPtr = _arrayToHeap(inputs);
    let outputsPtr = _arrayToHeap(outputs);
    

    // Run the WASM function
    Module._foo(inputsPtr.byteOffset, outputsPtr.byteOffset);

    // Copy data from WASM heap
    outputs = _heapToArray(outputsPtr, outputs);

    // Free allocated memory
    _freeArray(inputsPtr);
    _freeArray(outputsPtr);

    let data_out_all=Array.from(outputs)
    ///////////////////////////////////////////////////////////
    const n = [501, 501, 9, 2];
    const n_ = math.cumsum([0, ...n]);
    let Output = [];
    for (let i = 0; i < n.length; i++) {
        Output[i] = data_out_all.slice(n_[i], n_[i + 1]);
    }

    return Output;
}

// JavaScript Array to Emscripten Heap
function _arrayToHeap(typedArray) {
    let numBytes = typedArray.byteLength;
    let ptr = Module._malloc(numBytes);
    let heapBytes = new Uint8Array(Module.HEAPU8.buffer, ptr, numBytes);
    heapBytes.set(new Uint8Array(typedArray.buffer));
    return heapBytes;
}

// Emscripten Heap to JavaScript Array
function _heapToArray(heapBytes, typedArray) {
    return new Float32Array(
        heapBytes.buffer,
        heapBytes.byteOffset,
        heapBytes.length / typedArray.BYTES_PER_ELEMENT
    );
}

// Free Heap
function _freeArray(heapBytes) {
    Module._free(heapBytes.byteOffset);
}