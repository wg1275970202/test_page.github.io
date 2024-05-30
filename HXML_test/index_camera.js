const video = document.getElementById('video');
const canvas = document.getElementById('canvas');
const captureButton = document.getElementById('captureButton');
const exposureInput = document.getElementById('exposure');

// Get access to the camera
navigator.mediaDevices.getUserMedia({ video: { facingMode: 'environment' } })
    .then(stream => {
        video.srcObject = stream;
        video.play();
    })
    .catch(err => {
        console.error("Error accessing camera: ", err);
    });

// Capture photo on button click
captureButton.addEventListener('click', () => {
    const exposureTime = parseInt(exposureInput.value);

    if ('ImageCapture' in window) {
        const track = video.srcObject.getVideoTracks()[0];
        const imageCapture = new ImageCapture(track);

        // Get photo capabilities
        imageCapture.getPhotoCapabilities().then(capabilities => {
            if (capabilities.exposureMode && capabilities.exposureMode.includes('manual')) {
                track.applyConstraints({
                    advanced: [{ exposureTime: exposureTime * 1000 }]
                }).then(() => {
                    return imageCapture.takePhoto();
                }).then(blob => {
                    const img = new Image();
                    img.src = URL.createObjectURL(blob);
                    img.onload = () => {
                        const ctx = canvas.getContext('2d');
                        ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
                    }
                }).catch(error => {
                    console.error("Error taking photo: ", error);
                    alert("Error taking photo: " + error.message);
                });
            } else {
                console.warn("Manual exposure mode not supported");
                alert("Manual exposure mode not supported by your camera.");
            }
        }).catch(error => {
            console.error("Error getting photo capabilities: ", error);
            alert("Error getting photo capabilities: " + error.message);
        });
    } else {
        console.error("ImageCapture API not supported");
        alert("ImageCapture API not supported by your browser.");
    }
});
