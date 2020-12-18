/*-- File: exttestc.cpp start --*/
/**
* Andy England @ SparkFun Electronics
* September 6, 2018
* https://github.com/sparkfun/pxt-light-bit
*
* Development environment specifics:
* Written in Microsoft PXT
* Tested with a SparkFun temt6000 sensor and micro:bit
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Please review the LICENSE.md file included with this example. If you have any questions
* or concerns with licensing, please contact techsupport@sparkfun.com.
* Distributed as-is; no warranty is given.
*/


#include <pxt.h>
#include <MicroBit.h>
#include <cstdint>
#include <math.h>


#include <stdint.h>
#include <stddef.h>
#include<stdarg.h>

void log(const char *msg) {
    uBit.serial.send(msg);
}

using namespace pxt;

namespace exttestc {

//% blockId=exttestb_initfcnn
//% block="Init Brain|number %inputs|number[] %hidden|number %outputs"
//% shim=exttestc::initfcnn
void initfcnn(int inputs, RefCollection &hidden, int outputs) {
	log("initfcnn-v030");
}


//% blockId=exttestb_fcnnfromjson
//% block="Json Brain|string %json"
//% shim=exttestc::fcnnfromjson
void fcnnfromjson(String json) {
	log("fcnnfromjson-v030\r\n");
	const char *jsonNN = PXT_STRING_DATA(json);
	log(jsonNN);
	log("\r\n");
}




//% blockId=exttestb_ftrain
//% block="Train with err result|number[] %input|number[] %expected_output"
//% shim=exttestc::ftrain
float ftrain(RefCollection &input, RefCollection &expected_output) {
	log("ftrain-v2");
}

//% blockId=exttestb_train
//% block="Train|number[] %input|number[] %expected_output"
//% shim=exttestc::train
void train(RefCollection &input, RefCollection &expected_output) {
	log("train-v2");
}



//% blockId=exttestb_predict
//% block="Predict|number[] %input|number[] %output"
//% shim=exttestc::predict
void predict(RefCollection &input, RefCollection &output) {
	log("predict-v030");
}


}


