function getSolImage(data, duration) {
    // Assuming data is a Float32Array
    let inputs = new Float32Array(data);
    let input_2 = new Float32Array([duration]); // Assuming duration is a scalar, not an array
    let outputs = new Float32Array(200); // Adjust size as needed

    // Move data to WASM heap
    let inputsPtr = _arrayToHeap(inputs);
    let input_2Ptr = _arrayToHeap(input_2);
    let outputsPtr = _arrayToHeap(outputs);

    // Run the WASM function
    Module._foo(inputsPtr.byteOffset, input_2Ptr.byteOffset, outputsPtr.byteOffset);

    // Copy data from WASM heap
    outputs = _heapToArray(outputsPtr, outputs);

    // Free allocated memory
    _freeArray(inputsPtr);
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
