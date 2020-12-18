


//% weight=70 icon="\u237E" color=#74DF00 block="AI"
namespace exttestc {

    //% weight=100 
    //% blockId=exttestb_initfcnn
    //% block="Init Brain|number %inputs|number[] %hidden|number %outputs"
    //% shim=exttestc::initfcnn
    export function initfcnn(inputs: number, hidden: number[], outputs: number): void {
    	basic.showString("sim:init")
    }

    //% weight=90 
    //% blockId=exttestb_fcnnfromjson
    //% block="Json Brain|string %json"
    //% shim=exttestc::fcnnfromjson
    export function fcnnfromjson(json: string): void {
    	basic.showString("v028:json")
    }

    //% weight=70 
    //% blockId=exttestb_train
    //% block="Train|number[] %input|number[] %expected_output"
    //% shim=exttestc::train
    export function train(input: number[], expected_output: number[]): void {
    	basic.showString("sim-train")
    }

    //% weight=60 
    //% blockId=exttestb_ftrain
    //% block="Train with err result|number[] %input|number[] %expected_output"
    //% shim=exttestc::ftrain
    export function ftrain(input: number[], expected_output: number[]): number {
    	basic.showString("sim-ftrain")
        return 1
    }

    //% weight=50 
    //% blockId=exttestb_predict
    //% block="Predict|number[] %input|number[] %output"
    //% shim=exttestc::predict
    export function predict(input: number[], output: number[]): void {
    	basic.showString("v028:predict")
    }


 }
