function getSolImage(data_, duration) {


    // downsample
    let interval = 48;
    let length = Math.ceil(data_.length / interval);
    let sampledData = new Float32Array(1000 * 30);// 30 seconds
    for (let i = 0; i < length; i++) {
        sampledData[i] = data_[i * interval];
    }

    // Assuming data is a Float32Array
    let input_1 = new Float32Array(sampledData);
    let input_2 = new Float32Array([duration]); // Assuming duration is a scalar, not an array
    let outputs = new Float32Array(20000); // Adjust size as needed

    // Move data to WASM heap
    let input_1Ptr = _arrayToHeap(input_1);
    let input_2Ptr = _arrayToHeap(input_2);
    let outputsPtr = _arrayToHeap(outputs);

    // Run the WASM function
    Module._foo(input_1Ptr.byteOffset, input_2Ptr.byteOffset, outputsPtr.byteOffset);

    // Copy data from WASM heap
    outputs = _heapToArray(outputsPtr, outputs);

    // Free allocated memory
    _freeArray(input_1Ptr);
    _freeArray(input_2Ptr);
    _freeArray(outputsPtr);

    return Array.from(outputs);
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
