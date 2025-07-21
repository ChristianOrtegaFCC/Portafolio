    var context;
    var sourceNode;
    var analyser;
    var analyser2;
	var b_setup=false;


function setupSound() {
        if (! window.AudioContext) {
            if (! window.webkitAudioContext) {
                alert('no audiocontext found');
            }
            window.AudioContext = window.webkitAudioContext;
        }
        context = new AudioContext();

        // setup a analyzer
        analyser = context.createAnalyser();
        analyser.smoothingTimeConstant = 0.4;
        analyser.fftSize = 1024;

        analyser2 = context.createAnalyser();
        analyser2.smoothingTimeConstant = 0.4;
        analyser2.fftSize = 1024;

        // create a buffer source node
        sourceNode = context.createBufferSource();
        var splitter = context.createChannelSplitter();

        // connect the source to the analyser and the splitter
        sourceNode.connect(splitter);

        // connect one of the outputs from the splitter to
        // the analyser
        splitter.connect(analyser,0);
        splitter.connect(analyser2,1);

        // and connect to destination
        sourceNode.connect(context.destination);

        context = new AudioContext();
		b_setup=true;
    }


    function getAverageVolume(array) {
        var values = 0;
        var average;

        var length = array.length;

        // get all the frequency amplitudes
        for (var i = 0; i < length; i++) {
            values += array[i];
        }

        average = values / length;
        return average;
    }

    function playSound(buffer) {
        sourceNode.buffer = buffer;
        sourceNode.start(0);
    }

    // load the specified sound
    function loadSound(url) {
        var request = new XMLHttpRequest();
        request.open('GET', url, true);
        request.responseType = 'arraybuffer';

        // When loaded decode the data
        request.onload = function() {

            // decode the data
            context.decodeAudioData(request.response, function(buffer) {
                // when the audio is decoded play the sound
                playSound(buffer);
            }, onError);
        }
        request.send();
    }

    function onError(e) {
        console.log(e);
    }

