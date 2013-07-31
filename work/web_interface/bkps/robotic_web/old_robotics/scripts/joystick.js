//Joy stimulation in browser

//	 __________ _   _ ____    ____   ___  ____   ___ _____ ___ ____ ____  
//	|__  / ____| | | / ___|  |  _ \ / _ \| __ ) / _ \_   _|_ _/ ___/ ___| 
//	  / /|  _| | | | \___ \  | |_) | | | |  _ \| | | || |  | | |   \___ \ 
//	 / /_| |___| |_| |___) | |  _ <| |_| | |_) | |_| || |  | | |___ ___) |
//	/____|_____|\___/|____/  |_| \_\\___/|____/ \___/ |_| |___\____|____/ 
                                                                      


function moveForward(){
	console.log('Move Forward button clicked.....');
	main(1);
}
function moveBackward(){

	console.log('Move Backward button clicked.....');
	main(2);
}

function turnLeft(){

	console.log('Turn Left button clicked.....');
	main(3);
}

function turnRight(){

	console.log('Turn Right button clicked.....');
	main(4);
}

function emerStop(){

	console.log('Emergency Stop button clicked.....');
	main(5);
}


function main(x, z){

	if (typeof z === 'undefined'){
		console.log("Button pressed is "+ x);
		var button = x;
		var z = 0; 
	}
	else{

		console.log("x-axis  : " + x + ",  z-axis  :  " + z);
	
		var x_axis = x*1000;
		var z_axis = z*1000;
		x = Math.floor(x_axis);
		z = Math.floor(z_axis);
		console.log("Aftur floor x-axis  : " + x + ",  z-axis  :  " + z);
	}

	
	// Connecting to ROS
	// -----------------
	var ros = new ROS();

	// If there is an error on the backend, an 'error' emit will be emitted.
	ros.on('error', function(error) {
  		console.log(error);
	});

	// Create a connection to the rosbridge WebSocket server.
	ros.connect('ws://localhost:9090');



	// Calling a service
	// -----------------

	// First, we create a Service client with details of the service's name and
	// service type.
/*	var addTwoIntsClient = new ros.Service({
  		name        : '/add_two_ints',
  		serviceType : 'rospy_tutorials/AddTwoInts'
	});

*/	// Then we create a Service Request. The object we pass in to
	// ros.ServiceRequest matches the fields defined in the rospy_tutorials'
	// AddTwoInts.srv file.

/*	var data_to_send = button
	var request = new ros.ServiceRequest({ A: button, B: buttons});


*/
	// -----------------

	// First, we create a Service client with details of the service's name and
	// service type.
	var addTwoIntsClient = new ros.Service({
  		name        : '/add_two_ints',
  		serviceType : 'rospy_tutorials/AddTwoInts'
	});

	// Then we create a Service Request. The object we pass in to
	// ros.ServiceRequest matches the fields defined in the rospy_tutorials'
	// AddTwoInts.srv file.

	var request = new ros.ServiceRequest({ A: x, B: z});

	// Finally, we call the /add_two_ints service and get back the results in the
	// callback. The result is a ros.ServiceResponse object.
	addTwoIntsClient.callService(request, function(result) {
  		console.log('Result for service call on ' + addTwoIntsClient.name + ': ' + result.sum);});


}
