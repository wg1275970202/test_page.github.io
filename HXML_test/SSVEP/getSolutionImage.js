function getSolImage(data) {

    let inputs = data;
    // let length = 750 * 750; // 28x28

    // for (let i = 0; i < length * 4; i = i + 4) {
    //     inputs.push(data[i]);
    //     inputs.push(data[i + 1]);
    //     inputs.push(data[i + 2]);
    // }


    //console.log(inputs); // Create Data var
    var Inputs = new Float64Array(inputs);
    //var Inputs = new Uint8Array(data.buffer);
    var Outputs = new Float64Array(48000);

    // Move Data to Heap var
    var Outputsbytes = _arrayToHeap(Outputs);
    var Inputsbytes = _arrayToHeap(Inputs);

    // Run Function
    //Module._identifyDigits_debug_initialize(); // took this out (need to call this once)
    Module._foo(Inputsbytes.byteOffset, Outputsbytes.byteOffset)
    //Module._solveSudokuImage_codegen(Inputsbytes.byteOffset, Outputsbytes.byteOffset)
    //Module._identifyDigits_debug_terminate(); // no need to call anyways..
    // Copy Data from Heap 
    Outputs = _heapToArray(Outputsbytes, Outputs);
    var outputs = Array.from(Outputs);

    _freeArray(Inputsbytes);
    _freeArray(Outputsbytes);

    //[r, g, b, a, r, g, b, a, ...]
    // for (let i = 0; i < data.length; i += 4) {
    //     data[i] = outputs[i];
    //     data[i + 1] = outputs[i + 1];
    //     data[i + 2] = outputs[i + 2];
    // }
    return outputs
}

// JavaScript Array to Emscripten Heap
function _arrayToHeap(typedArray) {
    var numBytes = typedArray.length * typedArray.BYTES_PER_ELEMENT;
    var ptr = Module._malloc(numBytes);
    var heapBytes = new Uint8Array(Module.HEAPU8.buffer, ptr, numBytes);
    heapBytes.set(new Uint8Array(typedArray.buffer));
    return heapBytes;
}
// Emscripten Heap to JavasSript Array
function _heapToArray(heapBytes, array) {
    return new Float64Array(
        heapBytes.buffer,
        heapBytes.byteOffset,
        heapBytes.length / array.BYTES_PER_ELEMENT);
}

// Free Heap
function _freeArray(heapBytes) {
    Module._free(heapBytes.byteOffset);
}