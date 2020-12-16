


//% weight=70 icon="\u237E" color=#74DF00 block="AI"
namespace extensiontest {

    //% weight=100 
    //% blockId=extensiontest_initfcnn
    //% block="Init Brain|number %inputs|number[] %hidden|number %outputs"
    //% shim=extensiontest::initfcnn
    export function initfcnn(inputs: number, hidden: number[], outputs: number): void {
    	basic.showString("sim:init")
    }

    //% weight=90 
    //% blockId=extensiontest_fcnnfromjson
    //% block="Json Brain|string %json"
    //% shim=extensiontest::fcnnfromjson
    export function fcnnfromjson(json: string): void {
    	basic.showString("sim:json")
    }

    //% weight=70 
    //% blockId=extensiontest_train
    //% block="Train|number[] %input|number[] %expected_output"
    //% shim=extensiontest::train
    export function train(input: number[], expected_output: number[]): void {
    	basic.showString("sim-train")
    }

    //% weight=60 
    //% blockId=extensiontest_ftrain
    //% block="Train with err result|number[] %input|number[] %expected_output"
    //% shim=extensiontest::ftrain
    export function ftrain(input: number[], expected_output: number[]): number {
    	basic.showString("sim-ftrain")
        return 1
    }

    //% weight=50 
    //% blockId=extensiontest_predict
    //% block="Predict|number[] %input|number[] %output"
    //% shim=extensiontest::predict
    export function predict(input: number[], output: number[]): void {
    	basic.showString("sim-predict")
    }


 }
