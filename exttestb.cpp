/*-- File: exttestb.cpp start --*/
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

using namespace pxt;

namespace exttestb {

//% blockId=exttestb_initfcnn
//% block="Init Brain|number %inputs|number[] %hidden|number %outputs"
//% shim=exttestb::initfcnn
void initfcnn(int inputs, RefCollection &hidden, int outputs) {
	uBit.serial.send("initfcnn-v2");
}


//% blockId=exttestb_fcnnfromjson
//% block="Json Brain|string %json"
//% shim=exttestb::fcnnfromjson
void fcnnfromjson(String json) {
	uBit.serial.send("fcnnfromjson-v2");
}




//% blockId=exttestb_ftrain
//% block="Train with err result|number[] %input|number[] %expected_output"
//% shim=exttestb::ftrain
float ftrain(RefCollection &input, RefCollection &expected_output) {
	uBit.serial.send("ftrain-v2");
}

//% blockId=exttestb_train
//% block="Train|number[] %input|number[] %expected_output"
//% shim=exttestb::train
void train(RefCollection &input, RefCollection &expected_output) {
	uBit.serial.send("train-v2");
}



//% blockId=exttestb_predict
//% block="Predict|number[] %input|number[] %output"
//% shim=exttestb::predict
void predict(RefCollection &input, RefCollection &output) {
	uBit.serial.send("predict-v2");
}


}

/*-- File: exttestb.cpp end --*/
/*-- File: common\logUtils.cpp start --*/
/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H



void logLn() {
	log("\r\n");
}

void logLn(const char *msg) {
	log(msg);
	logLn();
}

void logLnInt(int i) {
	logInt(i);
	logLn();
}
void logLnFloat(float f) {
	logFloat(f);
	logLn();
}

void logNamedInt(const char * name, int i) {
	log(name);
	log(": ");
	logInt(i);
	logLn();
}

void logNamedFloat(const char * name, float f) {
	log(name);
	log(": ");
	logFloat(f);
	logLn();
}

/*-- File: common\logUtils.cpp end --*/
/*-- #include "common\logUtils.h" start --*/
#ifndef LOGUTILS_H
#define LOGUTILS_H

#include <stdint.h>
#include <stddef.h>

void logLn();
void logLn(const char *msg);
void logLnInt(int i);
void logLnFloat(float f);

void logNamedInt(const char * name, int i);
void logNamedFloat(const char * name, float f);


#endif // LOGUTILS_H

/*-- File: json\DebugJsonParser.cpp start --*/
/*
 * DebugJsonParser.cpp
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

/*-- #include "json\DebugJsonParser.h" start --*/
/*
 * DebugJsonParser.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef DEBUGJSONPARSER_H_
#define DEBUGJSONPARSER_H_

/*-- #include "json\JsonParserIF.h" start --*/
/*
 * JsonParserIF.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef JSONPARSERIF_H_
#define JSONPARSERIF_H_

class JsonParserIF {

public:
	virtual void init(){};

	virtual void beginObject(const char* name){};  					// "obj_name: {"  -> beginObject("obj_name")
	virtual void endObject(){};                    					// "}" -> endObject();
	virtual void beginList(const char* name){};                    	// "[" -> beginList()
	virtual void endList(){};                      					// "]" -> endList()
	virtual void attribute(const char* name, const char* value){};	// "'attr_name': 'attr_value', -> attribute("attr_name", "attr_value")
	virtual void element(const char* value){};						// "'value'," -> element(value)
    virtual void unexpected(int char_pos){};						// "???" -> unexpected(char_pos);

	virtual void exit(){};

    virtual void* getResult() = 0;

    virtual ~JsonParserIF(){};

};

#endif /* JSONPARSERIF_H_ */


class DebugJsonParser: public JsonParserIF {
public:
	DebugJsonParser();

	void init();

	void beginObject(const char* name);
	void endObject();
	void beginList(const char* name);
	void endList();
	void attribute(const char* name, const char* value);
	void element(const char* value);
    void unexpected(int char_pos);

	void exit();

    void* getResult();

	~DebugJsonParser();
};

#endif /* DEBUGJSONPARSER_H_ */

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H

#include <stdio.h>



DebugJsonParser::DebugJsonParser() {
}


void DebugJsonParser::init() {
	log("init()\r\n");
}

void DebugJsonParser::beginObject(const char* name) {
	log("beginObject('");
	if (name != 0) {
		log(name);
	}
	log("')\r\n");
}


void DebugJsonParser::endObject() {
	log("endObject()\r\n");
}

void DebugJsonParser::beginList(const char* name) {
	log("beginList('");
	if (name != 0) {
		log(name);
	}
	log("')\r\n");
}

void DebugJsonParser::endList() {
	log("endList()\r\n");
}

void DebugJsonParser::attribute(const char* name, const char* value) {
	log("attribute('");
	if (name != 0) {
		log(name);
	}
	log("', '");
	if (value != 0) {
		log(value);
	}
	log("')\r\n");
}

void DebugJsonParser::element(const char* value) {
	log("element('");
	if (value != 0) {
		log(value);
	}
	log("')\r\n");
}


void DebugJsonParser::unexpected(int char_pos) {
	char buf[100];
	sprintf(buf, "json error before character %d!", char_pos);
	throwError(buf);
}

void DebugJsonParser::exit() {
	log("exit()\r\n");
}

void* DebugJsonParser::getResult() {
	log("getResult()\r\n");
	return 0;
}



DebugJsonParser::~DebugJsonParser() {
}


/*-- File: json\DebugJsonParser.cpp end --*/
/*-- #include "json\DebugJsonParser.h" start --*/
/*
 * DebugJsonParser.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef DEBUGJSONPARSER_H_
#define DEBUGJSONPARSER_H_

/*-- #include "json\JsonParserIF.h" start --*/
/*
 * JsonParserIF.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef JSONPARSERIF_H_
#define JSONPARSERIF_H_

class JsonParserIF {

public:
	virtual void init(){};

	virtual void beginObject(const char* name){};  					// "obj_name: {"  -> beginObject("obj_name")
	virtual void endObject(){};                    					// "}" -> endObject();
	virtual void beginList(const char* name){};                    	// "[" -> beginList()
	virtual void endList(){};                      					// "]" -> endList()
	virtual void attribute(const char* name, const char* value){};	// "'attr_name': 'attr_value', -> attribute("attr_name", "attr_value")
	virtual void element(const char* value){};						// "'value'," -> element(value)
    virtual void unexpected(int char_pos){};						// "???" -> unexpected(char_pos);

	virtual void exit(){};

    virtual void* getResult() = 0;

    virtual ~JsonParserIF(){};

};

#endif /* JSONPARSERIF_H_ */


class DebugJsonParser: public JsonParserIF {
public:
	DebugJsonParser();

	void init();

	void beginObject(const char* name);
	void endObject();
	void beginList(const char* name);
	void endList();
	void attribute(const char* name, const char* value);
	void element(const char* value);
    void unexpected(int char_pos);

	void exit();

    void* getResult();

	~DebugJsonParser();
};

#endif /* DEBUGJSONPARSER_H_ */

/*-- #include "json\JsonParserIF.h" start --*/
/*
 * JsonParserIF.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef JSONPARSERIF_H_
#define JSONPARSERIF_H_

class JsonParserIF {

public:
	virtual void init(){};

	virtual void beginObject(const char* name){};  					// "obj_name: {"  -> beginObject("obj_name")
	virtual void endObject(){};                    					// "}" -> endObject();
	virtual void beginList(const char* name){};                    	// "[" -> beginList()
	virtual void endList(){};                      					// "]" -> endList()
	virtual void attribute(const char* name, const char* value){};	// "'attr_name': 'attr_value', -> attribute("attr_name", "attr_value")
	virtual void element(const char* value){};						// "'value'," -> element(value)
    virtual void unexpected(int char_pos){};						// "???" -> unexpected(char_pos);

	virtual void exit(){};

    virtual void* getResult() = 0;

    virtual ~JsonParserIF(){};

};

#endif /* JSONPARSERIF_H_ */

/*-- File: json\NNJsonParser.cpp start --*/
/*
 * NNJsonParser.cpp
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

/*-- #include "json\NNJsonParser.h" start --*/
/*
 * NNJsonParser.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef NNJSONPARSER_H_
#define NNJSONPARSER_H_

/*-- #include "json\JsonParserIF.h" start --*/
/*
 * JsonParserIF.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef JSONPARSERIF_H_
#define JSONPARSERIF_H_

class JsonParserIF {

public:
	virtual void init(){};

	virtual void beginObject(const char* name){};  					// "obj_name: {"  -> beginObject("obj_name")
	virtual void endObject(){};                    					// "}" -> endObject();
	virtual void beginList(const char* name){};                    	// "[" -> beginList()
	virtual void endList(){};                      					// "]" -> endList()
	virtual void attribute(const char* name, const char* value){};	// "'attr_name': 'attr_value', -> attribute("attr_name", "attr_value")
	virtual void element(const char* value){};						// "'value'," -> element(value)
    virtual void unexpected(int char_pos){};						// "???" -> unexpected(char_pos);

	virtual void exit(){};

    virtual void* getResult() = 0;

    virtual ~JsonParserIF(){};

};

#endif /* JSONPARSERIF_H_ */


class NN;
class Vect;

class NNJsonParser: public JsonParserIF {

private:

	enum ListTypes {
		NONE,
		ELEM_HIDDEN_LAYERS_SIZE,
		ELEM_COEFS,
		ELEM_INTERCEPTS
	};
	ListTypes current_list;
	int element_level;
	int element_pos[3];

	NN *nn;
	int input_size;
	Vect *hidden_layers_size;
	int output_size;
	int activation_function;


public:
	NNJsonParser();

	void init();

	void beginObject(const char* name);
	void endObject();
	void beginList(const char* name);
	void endList();
	void attribute(const char* name, const char* value);
	void element(const char* value);
    void unexpected(int char_pos);

	void exit();

    void* getResult();

private:
	void initNN();

public:
	~NNJsonParser();

};

#endif /* NNJSONPARSER_H_ */

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-- #include "neuralnets\NN.h" start --*/
#ifndef NN_H
#define NN_H

class Vect;
class NNLayer;

class NN
{
	int num_input;
	int num_layers;
	NNLayer **layers;

public:

	NN(int num_input);
	void addLayer(int num_output);

	int getNumLayers()  const;
	NNLayer* getLayer(int n)  const;

	int getNumInput() const;
	int getNumOutput() const;

	Vect* forwardPropagate(const Vect *input);
	Vect* backwardPropagate(const Vect *expected_output, const Vect *last_output, float learning_rate);

	void print() const;

	void init_car_race_net();
	void init_car_race_netZERO();
	void init_car_race_netTEST();

	~NN();
};


#endif  // NNLAYER_H

/*-- #include "neuralnets\NNLayer.h" start --*/
#ifndef NNLAYER_H
#define NNLAYER_H

class Mat;
class Vect;

const int NNL_ACT_FUN_NONE=0, NNL_ACT_FUN_RELU=1, NNL_ACT_FUN_SIGMOID=2, NNL_ACT_FUN_SOFTMAX=3, NNL_ACT_FUN_TANHYP=4, NNL_ACT_FUN_UNDEF=99;

class NNLayer
{
	int num_input;
	int num_output;
	Mat *w;
	Vect *b;
	Vect *_z;
	Vect *_x;
	int act_fun;

public:

	NNLayer(int num_input, int num_output) : NNLayer(num_input, num_output, NNL_ACT_FUN_NONE) {}
	NNLayer(int num_input, int num_output, int activation_function);

	void setActivationFunction(int activation_function);

	Vect* forwardPropagate(const Vect* input);
	Vect* backwardPropagate(const Vect *e, float lr);

	int getNumInput() const;
	int getNumOutput() const;

	void print() const;

	Mat* getWeights() const;
	Vect* getBiases() const;

	~NNLayer();
};


#endif  // NNLAYER_H

/*-- #include "neuralnets\Vect.h" start --*/
#ifndef VECT_H
#define VECT_H

class Mat;

class Vect
{
	int     length;
	float   *data;

public:

	Vect(int length);
	Vect(int length, const float* data);
	Vect(const Vect *vect);
	Vect(const Vect& vect);
	Vect(const Mat *mat);
	int getLength() const;
	float get(int n) const;
	void set(int n, float v);
	void multiply(const Vect *vect);
	void add(const Vect *vect);
	void sub(const Vect *vect);
	void sqr();
	float sum();
	Vect* multiplyR(const Mat *mat) const;
	Vect* multiplyC(const Mat *mat) const;
	Mat* multiplyRC(const Vect *vect) const;
	Mat* multiplyCR(const Vect *vect) const;


	void multiply(float f);

	Mat* toMatRow() const;
	Mat* toMatCol() const;

	void insert(float value, int pos=-1);

	void print() const;

	~Vect();
};


#endif

/*-- #include "neuralnets\Mat.h" start --*/
#ifndef MAT_H
#define MAT_H

class Vect;

class Mat
{
	int     nRows;
	int     nCols;
	float   *data;

public:

	Mat(int rows, int cols);
	Mat(const Mat *mat);
	Mat(const Mat& mat);
	Mat(int rows, int cols, const float *data);
	int getCols() const;
	int getRows() const;
	float get(int row, int col) const;
	void set(int row, int col, float v);
	Mat* transpose();

	void add(const Mat *mat);
	void sub(const Mat *mat);

	Mat* multiply(Mat *mat);
	Mat* multiplyT(Mat *mat);

	void multiply(float f);

	void addR(Vect *vect);
	void addC(Vect *vect);

	void print() const;

	~Mat();
};

#endif




NNJsonParser::NNJsonParser() {
	this->current_list = NONE;
	this->nn = 0;
	this->input_size = 0;
	this->hidden_layers_size = new Vect(0);
	this->output_size = 0;
	this->activation_function = NNL_ACT_FUN_UNDEF;
}


void NNJsonParser::init() {
}

void NNJsonParser::beginObject(const char* name) {
}


void NNJsonParser::endObject() {
}

void NNJsonParser::beginList(const char* name) {
	if (current_list != NONE) {
		element_level++;
		element_pos[element_level] = 0;
		return;
	}
	if (name == 0) {
		return;
	}
	if (strcmp(name, "hidden_layer_sizes") == 0) {
		current_list = ELEM_HIDDEN_LAYERS_SIZE;
	}
	else if (strcmp(name, "coefs") == 0) {
		initNN();
		current_list = ELEM_COEFS;
	}
	else if (strcmp(name, "intercepts") == 0) {
		current_list = ELEM_INTERCEPTS;
	}
	else {
		return;
	}
	element_level = 0;
	element_pos[element_level] = 0;
	log("reading ");
	log(name);
	log("\r\n");
//	logInt(element_level);
//	log(":");
//	logInt(element_pos[element_level]);
//	log("\r\n");
}

void NNJsonParser::endList() {
	if (current_list == NONE) {
		return;
	}
	element_level--;
	if (element_level < 0) {
		if (current_list == ELEM_HIDDEN_LAYERS_SIZE) {
			log("HIDDEN_LAYERS:");
			hidden_layers_size->print();
		}
		current_list = NONE;
	}
	else {
		element_pos[element_level]++;
	}
}

void NNJsonParser::attribute(const char* name, const char* value) {
	if (strcmp(name, "input_layer_size") == 0) {
		input_size = atoi(value);
		log(name);
		log("=");
		logInt(input_size);
		log("\r\n");
	}
	else if (strcmp(name, "output_layer_size") == 0) {
		output_size = atoi(value);
		log(name);
		log("=");
		logInt(output_size);
		log("\r\n");
	}
	else if (strcmp(name, "activation") == 0) {
		if (strcmp(value, "relu") == 0) {
			activation_function = NNL_ACT_FUN_RELU;
		}
		else if (strcmp(value, "tanh") == 0) {
			activation_function = NNL_ACT_FUN_TANHYP;
		}
		else if (strcmp(value, "sigmoid") == 0) {
			activation_function = NNL_ACT_FUN_SIGMOID;
		}
		else if (strcmp(value, "softmax") == 0) {
			activation_function = NNL_ACT_FUN_SOFTMAX;
		}
		else if (strcmp(value, "none") == 0) {
			activation_function = NNL_ACT_FUN_NONE;
		}
		else {
			char errMsg[100];
			sprintf(errMsg, "unknown activation function: '%s'", value);
			throwError(errMsg);
		}
	}

}

void NNJsonParser::element(const char* value) {
	switch (current_list) {
	case NONE:
		break;
	case ELEM_HIDDEN_LAYERS_SIZE: {
		int int_value = atoi(value);
		hidden_layers_size->insert(int_value);
		break;
	}
	case ELEM_COEFS: {
		NNLayer *layer = nn->getLayer(element_pos[0]);
		float f = char2float(value);
		layer->getWeights()->set(element_pos[1], element_pos[2], f);
		element_pos[element_level]++;
		break;
	}
	case ELEM_INTERCEPTS: {
		NNLayer *layer = nn->getLayer(element_pos[0]);
		float f = char2float(value);
		layer->getBiases()->set(element_pos[1], f);
		element_pos[element_level]++;
		break;
	}
	default:
		break;
	}
}


void NNJsonParser::unexpected(int char_pos) {
	char buf[100];
	sprintf(buf, "json error before character %d!", char_pos);
	throwError(buf);
}

void NNJsonParser::exit() {
}

void* NNJsonParser::getResult() {
	return nn;
}

void NNJsonParser::initNN() {
	if (nn != 0) {
		return;
	}
	if (input_size == 0) {
		throwError("input_layer_size not found in header!");
	}
	if (output_size == 0) {
		throwError("output_layer_size not found in header!");
	}
	if (hidden_layers_size->getLength() == 0) {
		throwError("hidden_layer_sizes not found in header!");
	}
	if (activation_function == NNL_ACT_FUN_UNDEF) {
		throwError("activation function not found in header!");
	}

	nn = new NN(input_size);
	for (int i=0; i<hidden_layers_size->getLength(); i++) {
		nn->addLayer(hidden_layers_size->get(i));
	}
	nn->addLayer(output_size);

	for (int i=0; i<nn->getNumLayers()-1; i++) {
		nn->getLayer(i)->setActivationFunction(activation_function);
	}
	nn->getLayer(nn->getNumLayers()-1)->setActivationFunction(NNL_ACT_FUN_SOFTMAX);
//	nn->getLayer(nn->getNumLayers()-1)->setActivationFunction(NNL_ACT_FUN_NONE);

}


NNJsonParser::~NNJsonParser() {
	delete hidden_layers_size;
	hidden_layers_size = 0;
}


/*-- File: json\NNJsonParser.cpp end --*/
/*-- #include "json\NNJsonParser.h" start --*/
/*
 * NNJsonParser.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef NNJSONPARSER_H_
#define NNJSONPARSER_H_

/*-- #include "json\JsonParserIF.h" start --*/
/*
 * JsonParserIF.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef JSONPARSERIF_H_
#define JSONPARSERIF_H_

class JsonParserIF {

public:
	virtual void init(){};

	virtual void beginObject(const char* name){};  					// "obj_name: {"  -> beginObject("obj_name")
	virtual void endObject(){};                    					// "}" -> endObject();
	virtual void beginList(const char* name){};                    	// "[" -> beginList()
	virtual void endList(){};                      					// "]" -> endList()
	virtual void attribute(const char* name, const char* value){};	// "'attr_name': 'attr_value', -> attribute("attr_name", "attr_value")
	virtual void element(const char* value){};						// "'value'," -> element(value)
    virtual void unexpected(int char_pos){};						// "???" -> unexpected(char_pos);

	virtual void exit(){};

    virtual void* getResult() = 0;

    virtual ~JsonParserIF(){};

};

#endif /* JSONPARSERIF_H_ */


class NN;
class Vect;

class NNJsonParser: public JsonParserIF {

private:

	enum ListTypes {
		NONE,
		ELEM_HIDDEN_LAYERS_SIZE,
		ELEM_COEFS,
		ELEM_INTERCEPTS
	};
	ListTypes current_list;
	int element_level;
	int element_pos[3];

	NN *nn;
	int input_size;
	Vect *hidden_layers_size;
	int output_size;
	int activation_function;


public:
	NNJsonParser();

	void init();

	void beginObject(const char* name);
	void endObject();
	void beginList(const char* name);
	void endList();
	void attribute(const char* name, const char* value);
	void element(const char* value);
    void unexpected(int char_pos);

	void exit();

    void* getResult();

private:
	void initNN();

public:
	~NNJsonParser();

};

#endif /* NNJSONPARSER_H_ */

/*-- File: json\Parser.cpp start --*/
/*-- #include "json\Parser.h" start --*/
#ifndef PARSER_H
#define PARSER_H

#define PARSER_BUF_MAXLEN 32

class Token;
class JsonParserIF;

class Parser
{
public:
	enum ParserState {
		STATE_INIT,
		STATE_NUMBER,
		STATE_TEXT,
		STATE_CHAR
	};

	enum Literal {
		LIT_UNKNOWN,
		LIT_WHITESPACE,
		LIT_NUM,
		LIT_LETTER,
		LIT_LEFT_ROUND_BRACKET,
		LIT_RIGHT_ROUND_BRACKET,
		LIT_LEFT_SQUARE_BRACKET,
		LIT_RIGHT_SQUARE_BRACKET,
		LIT_LEFT_CURLY_BRACKET,
		LIT_RIGHT_CURLY_BRACKET,
		LIT_COMMA,
		LIT_DOT,
		LIT_DASH,
		LIT_UNDERSCORE,
		LIT_PLUS,
		LIT_COLON,
		LIT_QUOTE

	};

private:
	char buf[PARSER_BUF_MAXLEN];
	int  buflen;
	ParserState parse_state;
	Token *token;
	Token *currentToken;
	bool expectCommaToken;
	int chars_parsed;
	JsonParserIF *jsonParser;

public:
	Parser(JsonParserIF *jsonParser);

	void parse(const char *text);
	void parse(char c);
	Literal getLiteral(char c);
	bool continuesCurrentToken(Literal lit);
	Token *getToken();
	void addToBuf(char c);
	void createNewToken(Literal lit);
	char finalizeCurrentToken(char c);

private:
	bool processTokens();
	Token *nextNonEmptyToken(Token *tok);

public:
	~Parser();

};


#endif  // PARSER_H

/*-- #include "json\Token.h" start --*/
#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

class Token
{
public:
	enum TokenType {
		TOK_NONE,
		TOK_ERROR,
		TOK_NUMBER,
		TOK_TEXT,
		TOK_LEFT_CURL_BR,
		TOK_RIGHT_CURL_BR,
		TOK_LEFT_SQR_BR,
		TOK_RIGHT_SQR_BR,
		TOK_COLON,
		TOK_COMMA,
		TOK_STRING
	};

public:
	TokenType type;
	char *value;
	Token *next;

public:
	Token(TokenType type, const char *value=0, int valueLen=0);

	void setValue(const char *newValue, int newValueLen=0);

	size_t toString(char *buf, size_t maxlen);
	Token *nextToken();

	~Token();
};


#endif // TOKEN_H

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H

/*-- #include "json\JsonParserIF.h" start --*/
/*
 * JsonParserIF.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef JSONPARSERIF_H_
#define JSONPARSERIF_H_

class JsonParserIF {

public:
	virtual void init(){};

	virtual void beginObject(const char* name){};  					// "obj_name: {"  -> beginObject("obj_name")
	virtual void endObject(){};                    					// "}" -> endObject();
	virtual void beginList(const char* name){};                    	// "[" -> beginList()
	virtual void endList(){};                      					// "]" -> endList()
	virtual void attribute(const char* name, const char* value){};	// "'attr_name': 'attr_value', -> attribute("attr_name", "attr_value")
	virtual void element(const char* value){};						// "'value'," -> element(value)
    virtual void unexpected(int char_pos){};						// "???" -> unexpected(char_pos);

	virtual void exit(){};

    virtual void* getResult() = 0;

    virtual ~JsonParserIF(){};

};

#endif /* JSONPARSERIF_H_ */


Parser::Parser(JsonParserIF *jsonParser) {
	this->buflen = 0;
	this->parse_state = STATE_INIT;
	this->token = new Token(Token::TOK_NONE);
	this->currentToken = this->token;
	this->jsonParser = jsonParser;
	this->expectCommaToken = false;
	this->chars_parsed = 0;
}

void Parser::parse(const char *text) {
	const char* pc = text;
	jsonParser->init();
	while (*pc) {
		parse(*pc++);
	}
	finalizeCurrentToken(' ');
	jsonParser->exit();
}

void Parser::parse(char c) {
	chars_parsed++;
	Literal lit = getLiteral(c);
	if (continuesCurrentToken(lit)) {
		addToBuf(c);
	}
	else {
		c = finalizeCurrentToken(c);
		if (c == '\0') {
			createNewToken(LIT_WHITESPACE);
		}
		else {
			createNewToken(lit);
			addToBuf(c);
		}
	}
}

void Parser::addToBuf(char c) {
	if (buflen >= PARSER_BUF_MAXLEN) {
		// TODO: throw exception? enlarge buf? ignore?
		// -> ignore
		return;
	}
	buf[buflen++] = c;
}

char Parser::finalizeCurrentToken(char c) {
	switch (currentToken->type) {
	case Token::TOK_TEXT:
		currentToken->setValue(buf, buflen);
		break;
	case Token::TOK_STRING:
		currentToken->setValue(buf+1, buflen-1);
		c = '\0';
		break;
	case Token::TOK_NUMBER:
		currentToken->setValue(buf, buflen);
		break;
	default:
		break;
	}
	buflen = 0;
	processTokens();
	return c;

}

void Parser::createNewToken(Literal lit) {
	Token::TokenType type = Token::TOK_NONE;
	switch (lit) {
	case LIT_COLON:
		type = Token::TOK_COLON;
		break;
	case LIT_COMMA:
		type = Token::TOK_COMMA;
		break;
	case LIT_DASH:
		type = Token::TOK_NUMBER;
		break;
	case LIT_DOT:
		type = Token::TOK_NUMBER;
		break;
	case LIT_LEFT_CURLY_BRACKET:
		type = Token::TOK_LEFT_CURL_BR;
		break;
	case LIT_LEFT_SQUARE_BRACKET:
		type = Token::TOK_LEFT_SQR_BR;
		break;
	case LIT_LETTER:
		type = Token::TOK_TEXT;
		break;
	case LIT_NUM:
		type = Token::TOK_NUMBER;
		break;
	case LIT_QUOTE:
		type = Token::TOK_STRING;
		break;
	case LIT_RIGHT_CURLY_BRACKET:
		type = Token::TOK_RIGHT_CURL_BR;
		break;
	case LIT_RIGHT_SQUARE_BRACKET:
		type = Token::TOK_RIGHT_SQR_BR;
		break;
	case LIT_WHITESPACE:
		type = Token::TOK_NONE;
		break;
	default:
		type = Token::TOK_ERROR;
	}
	currentToken->next = new Token(type);
	currentToken = currentToken->next;
}


bool Parser::continuesCurrentToken(Literal lit) {
	switch (currentToken->type) {
	case Token::TOK_TEXT:
		return (lit == LIT_LETTER) || (lit == LIT_NUM) || (lit == LIT_UNDERSCORE);
	case Token::TOK_STRING:
		return (lit != LIT_QUOTE);
	case Token::TOK_NUMBER:
		return (lit == LIT_NUM) || (lit == LIT_DOT) || (lit == LIT_DASH) || (lit == LIT_PLUS) || (lit == LIT_LETTER);
	case Token::TOK_NONE:
		return (lit == LIT_WHITESPACE);
	default:
		return false;
	}
}


Parser::Literal Parser::getLiteral(char c) {
	if ((c >= '0') && (c <= '9')) {
		return LIT_NUM;
	}
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
		return LIT_LETTER;
	}
	switch (c)
	{
	case '{':
		return LIT_LEFT_CURLY_BRACKET;
	case '}':
		return LIT_RIGHT_CURLY_BRACKET;
	case '(':
		return LIT_LEFT_ROUND_BRACKET;
	case ')':
		return LIT_RIGHT_ROUND_BRACKET;
	case '[':
		return LIT_LEFT_SQUARE_BRACKET;
	case ']':
		return LIT_RIGHT_SQUARE_BRACKET;
	case ',':
		return LIT_COMMA;
	case '.':
		return LIT_DOT;
	case '-':
		return LIT_DASH;
	case '_':
		return LIT_UNDERSCORE;
	case '+':
		return LIT_PLUS;
	case ':':
		return LIT_COLON;
	case '\'':
	case '"':
		return LIT_QUOTE;
	case ' ':
	case '\t':
	case '\r':
	case '\n':
		return LIT_WHITESPACE;
	default:
		return LIT_UNKNOWN;
	}
}


Token *Parser::getToken() {
	return this->token;
}


Token *Parser::nextNonEmptyToken(Token *tok) {
	while ((tok != 0) && (tok->type == Token::TOK_NONE)) {
		tok = tok->nextToken();
	}
	return tok;
}

bool Parser::processTokens() {
	Token *tok = nextNonEmptyToken(getToken());
	if (tok == 0) {
		return false;
	}
	switch (tok->type) {
	case Token::TOK_LEFT_CURL_BR:
		if (expectCommaToken) {
			jsonParser->unexpected(chars_parsed);
			break;
		}
		jsonParser->beginObject(NULL);
		break;
	case Token::TOK_RIGHT_CURL_BR:
		jsonParser->endObject();
		expectCommaToken = true;
		break;
	case Token::TOK_LEFT_SQR_BR:
		if (expectCommaToken) {
			jsonParser->unexpected(chars_parsed);
			break;
		}
		jsonParser->beginList(NULL);
		break;
	case Token::TOK_RIGHT_SQR_BR:
		jsonParser->endList();
		expectCommaToken = true;
		break;
	case Token::TOK_TEXT:
	case Token::TOK_STRING:
	case Token::TOK_NUMBER: {
		if (expectCommaToken) {
			jsonParser->unexpected(chars_parsed);
			break;
		}
		Token *tok2 = nextNonEmptyToken(tok->nextToken());
		if (tok2 == 0) {
			return false;
		}
		if (tok2->type != Token::TOK_COLON) {
			const char *value = tok->value;
			switch (tok2->type) {
			case Token::TOK_COMMA:
				jsonParser->element(value);
				tok = tok2;   // eat the comma
				break;
			case Token::TOK_RIGHT_CURL_BR:
			case Token::TOK_RIGHT_SQR_BR:
				jsonParser->element(value);
				break;
			default:
				jsonParser->unexpected(chars_parsed);
				tok = tok2;
				break;
			}
			break;
		}
		tok2 = nextNonEmptyToken(tok2->nextToken());
		if (tok2 == 0) {
			return false;
		}
		const char *name = tok->value;
		switch (tok2->type) {
		case Token::TOK_LEFT_CURL_BR:
			jsonParser->beginObject(name);
			break;
		case Token::TOK_LEFT_SQR_BR:
			jsonParser->beginList(name);
			break;
		case Token::TOK_TEXT:
		case Token::TOK_STRING:
		case Token::TOK_NUMBER: {
				Token *tok3 = nextNonEmptyToken(tok2->nextToken());
				if (tok3 == 0) {
					return false;
				}
				const char *value = tok2->value;
				switch (tok3->type) {
				case Token::TOK_COMMA:
					jsonParser->attribute(name, value);
					tok2 = tok3; // eat the comma
					break;
				case Token::TOK_RIGHT_CURL_BR:
				case Token::TOK_RIGHT_SQR_BR:
					jsonParser->attribute(name, value);
					break;
				default:
					jsonParser->unexpected(chars_parsed);
					tok2 = tok3;
					break;
				}
			}
			break;
		default:
			jsonParser->unexpected(chars_parsed);
			break;
		}
		tok = tok2;
		break;
	}
	case Token::TOK_COMMA:
		if (!expectCommaToken) {
			jsonParser->unexpected(chars_parsed);
		}
		expectCommaToken = false;
		break;
	default:
		jsonParser->unexpected(chars_parsed);
		break;
	}
	Token *t = getToken();
	while ((t != 0 ) && (t != tok)) {
		Token *t2 = t;
		t = t->nextToken();
		delete t2;
	}
	if (t == tok) {
		t = tok->nextToken();
		delete tok;
	}
	if (t != 0) {
		token = t;
	}
	else {
		token = new Token(Token::TOK_NONE);
		this->currentToken = this->token;
	}
	return true;
}


Parser::~Parser() {
	while (token != 0) {
		Token *t = token;
		token = t->nextToken();
		delete t;
	}
}


/*-- File: json\Parser.cpp end --*/
/*-- #include "json\Parser.h" start --*/
#ifndef PARSER_H
#define PARSER_H

#define PARSER_BUF_MAXLEN 32

class Token;
class JsonParserIF;

class Parser
{
public:
	enum ParserState {
		STATE_INIT,
		STATE_NUMBER,
		STATE_TEXT,
		STATE_CHAR
	};

	enum Literal {
		LIT_UNKNOWN,
		LIT_WHITESPACE,
		LIT_NUM,
		LIT_LETTER,
		LIT_LEFT_ROUND_BRACKET,
		LIT_RIGHT_ROUND_BRACKET,
		LIT_LEFT_SQUARE_BRACKET,
		LIT_RIGHT_SQUARE_BRACKET,
		LIT_LEFT_CURLY_BRACKET,
		LIT_RIGHT_CURLY_BRACKET,
		LIT_COMMA,
		LIT_DOT,
		LIT_DASH,
		LIT_UNDERSCORE,
		LIT_PLUS,
		LIT_COLON,
		LIT_QUOTE

	};

private:
	char buf[PARSER_BUF_MAXLEN];
	int  buflen;
	ParserState parse_state;
	Token *token;
	Token *currentToken;
	bool expectCommaToken;
	int chars_parsed;
	JsonParserIF *jsonParser;

public:
	Parser(JsonParserIF *jsonParser);

	void parse(const char *text);
	void parse(char c);
	Literal getLiteral(char c);
	bool continuesCurrentToken(Literal lit);
	Token *getToken();
	void addToBuf(char c);
	void createNewToken(Literal lit);
	char finalizeCurrentToken(char c);

private:
	bool processTokens();
	Token *nextNonEmptyToken(Token *tok);

public:
	~Parser();

};


#endif  // PARSER_H

/*-- File: json\Token.cpp start --*/
#include <stdio.h>
#include<string.h>

/*-- #include "json\Token.h" start --*/
#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

class Token
{
public:
	enum TokenType {
		TOK_NONE,
		TOK_ERROR,
		TOK_NUMBER,
		TOK_TEXT,
		TOK_LEFT_CURL_BR,
		TOK_RIGHT_CURL_BR,
		TOK_LEFT_SQR_BR,
		TOK_RIGHT_SQR_BR,
		TOK_COLON,
		TOK_COMMA,
		TOK_STRING
	};

public:
	TokenType type;
	char *value;
	Token *next;

public:
	Token(TokenType type, const char *value=0, int valueLen=0);

	void setValue(const char *newValue, int newValueLen=0);

	size_t toString(char *buf, size_t maxlen);
	Token *nextToken();

	~Token();
};


#endif // TOKEN_H

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H



Token::Token(TokenType type, const char *value, int valueLen) {
	this->type = type;
	this->next = 0;
	if (valueLen == 0) {
		this->value = 0;
	}
	else {
		this->value = new char[valueLen+1];
		strncpy(this->value, value, valueLen);
		this->value[valueLen] = '\0';
	}
}


size_t Token::toString(char *buf, size_t maxlen) {
	switch (type) {
	case TOK_COLON:
		return snprintf(buf, maxlen, ":");
	case TOK_COMMA:
		return snprintf(buf, maxlen, ",");
	case TOK_LEFT_CURL_BR:
		return snprintf(buf, maxlen, "{");
	case TOK_RIGHT_CURL_BR:
		return snprintf(buf, maxlen, "}");
	case TOK_LEFT_SQR_BR:
		return snprintf(buf, maxlen, "[");
	case TOK_RIGHT_SQR_BR:
		return snprintf(buf, maxlen, "]");
	case TOK_NONE:
		buf[0] = '\0';
		return 0;
	case TOK_NUMBER: {
		char numbuf[20];
		float f = char2float(this->value);
		float2char(numbuf, f, 4);
		return snprintf(buf, maxlen, "%s", numbuf);
	}
	case TOK_TEXT:
		return snprintf(buf, maxlen, "%s", this->value);
	case TOK_STRING:
		return snprintf(buf, maxlen, "'%s'", this->value);
	default:
		return snprintf(buf, maxlen, "???");
	}
}

Token *Token::nextToken() {
	return this->next;

};

void Token::setValue(const char *newValue, int newValueLen) {
	if (value != 0) {
		delete value;
		value = 0;
	}
	if (newValue == 0) {
		return;
	}
	if (newValueLen == 0) {
		newValueLen = strlen(newValue);
	}
	this->value = new char[newValueLen+1];
	strncpy(this->value, newValue, newValueLen);
	this->value[newValueLen] = '\0';
}


Token::~Token() {
	if (value != 0) {
		delete value;
		value = 0;
	}
}


/*-- File: json\Token.cpp end --*/
/*-- #include "json\Token.h" start --*/
#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

class Token
{
public:
	enum TokenType {
		TOK_NONE,
		TOK_ERROR,
		TOK_NUMBER,
		TOK_TEXT,
		TOK_LEFT_CURL_BR,
		TOK_RIGHT_CURL_BR,
		TOK_LEFT_SQR_BR,
		TOK_RIGHT_SQR_BR,
		TOK_COLON,
		TOK_COMMA,
		TOK_STRING
	};

public:
	TokenType type;
	char *value;
	Token *next;

public:
	Token(TokenType type, const char *value=0, int valueLen=0);

	void setValue(const char *newValue, int newValueLen=0);

	size_t toString(char *buf, size_t maxlen);
	Token *nextToken();

	~Token();
};


#endif // TOKEN_H

/*-- File: json\VectJsonParser.cpp start --*/
/*
 * VectJsonParser.cpp
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

/*-- #include "json\VectJsonParser.h" start --*/
/*
 * VectJsonParser.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef VECTJSONPARSER_H_
#define VECTJSONPARSER_H_

/*-- #include "json\JsonParserIF.h" start --*/
/*
 * JsonParserIF.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef JSONPARSERIF_H_
#define JSONPARSERIF_H_

class JsonParserIF {

public:
	virtual void init(){};

	virtual void beginObject(const char* name){};  					// "obj_name: {"  -> beginObject("obj_name")
	virtual void endObject(){};                    					// "}" -> endObject();
	virtual void beginList(const char* name){};                    	// "[" -> beginList()
	virtual void endList(){};                      					// "]" -> endList()
	virtual void attribute(const char* name, const char* value){};	// "'attr_name': 'attr_value', -> attribute("attr_name", "attr_value")
	virtual void element(const char* value){};						// "'value'," -> element(value)
    virtual void unexpected(int char_pos){};						// "???" -> unexpected(char_pos);

	virtual void exit(){};

    virtual void* getResult() = 0;

    virtual ~JsonParserIF(){};

};

#endif /* JSONPARSERIF_H_ */


class Vect;

class VectJsonParser: public JsonParserIF {

private:
	Vect *vect;

public:
	VectJsonParser();
	void element(const char* value);
    void* getResult();
	~VectJsonParser();

};

#endif /* VECTJSONPARSER_H_ */

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H


/*-- #include "neuralnets\Vect.h" start --*/
#ifndef VECT_H
#define VECT_H

class Mat;

class Vect
{
	int     length;
	float   *data;

public:

	Vect(int length);
	Vect(int length, const float* data);
	Vect(const Vect *vect);
	Vect(const Vect& vect);
	Vect(const Mat *mat);
	int getLength() const;
	float get(int n) const;
	void set(int n, float v);
	void multiply(const Vect *vect);
	void add(const Vect *vect);
	void sub(const Vect *vect);
	void sqr();
	float sum();
	Vect* multiplyR(const Mat *mat) const;
	Vect* multiplyC(const Mat *mat) const;
	Mat* multiplyRC(const Vect *vect) const;
	Mat* multiplyCR(const Vect *vect) const;


	void multiply(float f);

	Mat* toMatRow() const;
	Mat* toMatCol() const;

	void insert(float value, int pos=-1);

	void print() const;

	~Vect();
};


#endif


VectJsonParser::VectJsonParser() {
	this->vect = new Vect(0);
}

void VectJsonParser::element(const char* value) {
	if (vect != 0) {
		float f = char2float(value);
		vect->insert(f);
	}
}

void* VectJsonParser::getResult() {
	Vect *result = vect;
	vect = 0;
	return result;
}
VectJsonParser::~VectJsonParser() {
	if (vect != 0) {
		delete vect;
	}
	vect = 0;
}


/*-- File: json\VectJsonParser.cpp end --*/
/*-- #include "json\VectJsonParser.h" start --*/
/*
 * VectJsonParser.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef VECTJSONPARSER_H_
#define VECTJSONPARSER_H_

/*-- #include "json\JsonParserIF.h" start --*/
/*
 * JsonParserIF.h
 *
 *  Created on: 29.02.2020
 *      Author: A307131
 */

#ifndef JSONPARSERIF_H_
#define JSONPARSERIF_H_

class JsonParserIF {

public:
	virtual void init(){};

	virtual void beginObject(const char* name){};  					// "obj_name: {"  -> beginObject("obj_name")
	virtual void endObject(){};                    					// "}" -> endObject();
	virtual void beginList(const char* name){};                    	// "[" -> beginList()
	virtual void endList(){};                      					// "]" -> endList()
	virtual void attribute(const char* name, const char* value){};	// "'attr_name': 'attr_value', -> attribute("attr_name", "attr_value")
	virtual void element(const char* value){};						// "'value'," -> element(value)
    virtual void unexpected(int char_pos){};						// "???" -> unexpected(char_pos);

	virtual void exit(){};

    virtual void* getResult() = 0;

    virtual ~JsonParserIF(){};

};

#endif /* JSONPARSERIF_H_ */


class Vect;

class VectJsonParser: public JsonParserIF {

private:
	Vect *vect;

public:
	VectJsonParser();
	void element(const char* value);
    void* getResult();
	~VectJsonParser();

};

#endif /* VECTJSONPARSER_H_ */

/*-- File: neuralnets\Mat.cpp start --*/
/*-- #include "neuralnets\Mat.h" start --*/
#ifndef MAT_H
#define MAT_H

class Vect;

class Mat
{
	int     nRows;
	int     nCols;
	float   *data;

public:

	Mat(int rows, int cols);
	Mat(const Mat *mat);
	Mat(const Mat& mat);
	Mat(int rows, int cols, const float *data);
	int getCols() const;
	int getRows() const;
	float get(int row, int col) const;
	void set(int row, int col, float v);
	Mat* transpose();

	void add(const Mat *mat);
	void sub(const Mat *mat);

	Mat* multiply(Mat *mat);
	Mat* multiplyT(Mat *mat);

	void multiply(float f);

	void addR(Vect *vect);
	void addC(Vect *vect);

	void print() const;

	~Mat();
};

#endif

/*-- #include "neuralnets\Vect.h" start --*/
#ifndef VECT_H
#define VECT_H

class Mat;

class Vect
{
	int     length;
	float   *data;

public:

	Vect(int length);
	Vect(int length, const float* data);
	Vect(const Vect *vect);
	Vect(const Vect& vect);
	Vect(const Mat *mat);
	int getLength() const;
	float get(int n) const;
	void set(int n, float v);
	void multiply(const Vect *vect);
	void add(const Vect *vect);
	void sub(const Vect *vect);
	void sqr();
	float sum();
	Vect* multiplyR(const Mat *mat) const;
	Vect* multiplyC(const Mat *mat) const;
	Mat* multiplyRC(const Vect *vect) const;
	Mat* multiplyCR(const Vect *vect) const;


	void multiply(float f);

	Mat* toMatRow() const;
	Mat* toMatCol() const;

	void insert(float value, int pos=-1);

	void print() const;

	~Vect();
};


#endif

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H

#include <stdio.h>


Mat::Mat(int rows, int cols)
{
	this->nRows = rows;
	this->nCols = cols;
	data = new float[rows*cols];
}

Mat::Mat(const Mat *mat)
{
	this->nRows = mat->getRows();
	this->nCols = mat->getCols();
	int size = nRows * nCols;
	this->data = new float[size];
	for (int i = 0; i < size; i++) {
		data[i] = mat->data[i];
	}
}

Mat::Mat(const Mat& mat)
{
	this->nRows = mat.getRows();
	this->nCols = mat.getCols();
	int size = nRows * nCols;
	this->data = new float[size];
	for (int i = 0; i < size; i++) {
		data[i] = mat.data[i];
	}
}

Mat::Mat(int rows, int cols, const float *data) {
	this->nRows = rows;
	this->nCols = cols;
	int size = nRows*nCols;
	this->data = new float[size];
	for (int i=0; i<size; i++) {
		this->data[i] = data[i];
	}
}

int Mat::getCols() const
{
	return nCols;
}

int Mat::getRows() const
{
	return nRows;
}

float Mat::get(int row, int col) const
{
	if (row < 0 || col < 0 || row >= nRows || col >= nCols) {
	    print();
		char buf[100];
		sprintf(buf, "\r\nrow: %d, col: %d\r\n", row, col);
		log(buf);
		throwError("Mat::get: index out of range");
	}
	return data[row*nCols + col];
}

void Mat::set(int row, int col, float v)
{
	if (row < 0 || col < 0 || row >= nRows || col >= nCols) {
	    print();
		char buf[100];
		sprintf(buf, "\r\nrow: %d, col: %d\r\n", row, col);
		log(buf);
		throwError("Mat::set: index out of range");
	}
	data[row*nCols + col] = v;
}

Mat* Mat::transpose()
{
	Mat* result = new Mat(nCols, nRows);
	for (int r = 0; r < nRows; r++) {
		for (int c = 0; c < nCols; c++) {
			result->set(c, r, get(r, c));
		}
	}
	return result;
}


void Mat::add(const Mat *mat) {
	if (getRows()!=mat->getRows() || getCols()!=mat->getCols() ) {
		print();
		mat->print();
		throwError("Mat::add: cols and rows do not match");
	}
	for (int r=0; r<nRows; r++) {
		for (int c=0; c<nCols; c++) {
			set(r,c, get(r,c)+mat->get(r,c));
		}
	}
}

void Mat::sub(const Mat *mat) {
	if (getRows()!=mat->getRows() || getCols()!=mat->getCols() ) {
		print();
		mat->print();
		throwError("Mat::sub: cols and rows do not match");
	}
	for (int r=0; r<nRows; r++) {
		for (int c=0; c<nCols; c++) {
			set(r,c, get(r,c)-mat->get(r,c));
		}
	}
}

Mat* Mat::multiply(Mat *matrix)
{
    int co = nCols;
    int ro = nRows;
	if (co != matrix->getRows()) {
		print();
		matrix->print();
		throwError("Mat::multiply: cols and rows do not match");
	}
	Mat *result = new Mat(ro, matrix->getCols());
	for (int r = 0; r < result->getRows(); r++)
	{
		for (int c = 0; c < result->getCols(); c++)
		{
			float v = 0.0;
			for (int i = 0; i < co; i++) {
				v += get(r, i) * matrix->get(i, c);
			}
			result->set(r, c, v);
		}
	}
	return result;
}


Mat* Mat::multiplyT(Mat *matrix)
{
    int co = nRows;
    int ro = nCols;
	if (co != matrix->getRows()) {
		print();
		matrix->print();
		log("TRANSPOSE\r\n");
		throwError("Mat::multiply: cols and rows do not match");
	}
	Mat *result = new Mat(ro, matrix->getCols());
	for (int r = 0; r < result->getRows(); r++)
	{
		for (int c = 0; c < result->getCols(); c++)
		{
			float v = 0.0;
			for (int i = 0; i < co; i++) {
				v += get(i, r) * matrix->get(i, c);
			}
			result->set(r, c, v);
		}
	}
	return result;
}


void Mat::multiply(float f) {
	for (int r=0; r<nRows; r++) {
		for (int c=0; c<nCols; c++) {
			set(r, c, get(r,c)*f);
		}
	}
}


void Mat::addR(Vect *vect) {
	if (vect->getLength() != nCols) {
		print();
		vect->print();
		throwError("Mat::addR: cols and vector-length do not match.");
	}
	for (int r=0; r<nRows; r++) {
		for (int i=0; i<nCols; i++) {
			float v = get(r,i) + vect->get(i);
			set(r, i, v);
		}
	}
}

void Mat::addC(Vect *vect) {
	if (vect->getLength() != nRows) {
		print();
		vect->print();
		throwError("Mat::addR: rows and vector-length do not match.");
	}
	for (int i=0; i<nRows; i++) {
		for (int c=0; c<nCols; c++) {
			float v = get(i,c) + vect->get(i);
			set(i, c, v);
		}
	}
}



void Mat::print() const {
	log("MAT\r\n");
	char buf[100];
	for (int r=0; r<nRows; r++) {
		for (int c=0; c<nCols; c++) {
			float v = get(r,c);
			int len = float2char(buf, v, 4);
			for (int i=len; i<10; i++) {
				log(" ");
			}
			log(buf);
		}
		log("\r\n");
	}
	log("\r\n");
}


Mat::~Mat()
{
	delete data;
	data = 0;
}

/*-- File: neuralnets\Mat.cpp end --*/
/*-- #include "neuralnets\Mat.h" start --*/
#ifndef MAT_H
#define MAT_H

class Vect;

class Mat
{
	int     nRows;
	int     nCols;
	float   *data;

public:

	Mat(int rows, int cols);
	Mat(const Mat *mat);
	Mat(const Mat& mat);
	Mat(int rows, int cols, const float *data);
	int getCols() const;
	int getRows() const;
	float get(int row, int col) const;
	void set(int row, int col, float v);
	Mat* transpose();

	void add(const Mat *mat);
	void sub(const Mat *mat);

	Mat* multiply(Mat *mat);
	Mat* multiplyT(Mat *mat);

	void multiply(float f);

	void addR(Vect *vect);
	void addC(Vect *vect);

	void print() const;

	~Mat();
};

#endif

/*-- File: neuralnets\NN.cpp start --*/
/*-- #include "neuralnets\Mat.h" start --*/
#ifndef MAT_H
#define MAT_H

class Vect;

class Mat
{
	int     nRows;
	int     nCols;
	float   *data;

public:

	Mat(int rows, int cols);
	Mat(const Mat *mat);
	Mat(const Mat& mat);
	Mat(int rows, int cols, const float *data);
	int getCols() const;
	int getRows() const;
	float get(int row, int col) const;
	void set(int row, int col, float v);
	Mat* transpose();

	void add(const Mat *mat);
	void sub(const Mat *mat);

	Mat* multiply(Mat *mat);
	Mat* multiplyT(Mat *mat);

	void multiply(float f);

	void addR(Vect *vect);
	void addC(Vect *vect);

	void print() const;

	~Mat();
};

#endif

/*-- #include "neuralnets\Vect.h" start --*/
#ifndef VECT_H
#define VECT_H

class Mat;

class Vect
{
	int     length;
	float   *data;

public:

	Vect(int length);
	Vect(int length, const float* data);
	Vect(const Vect *vect);
	Vect(const Vect& vect);
	Vect(const Mat *mat);
	int getLength() const;
	float get(int n) const;
	void set(int n, float v);
	void multiply(const Vect *vect);
	void add(const Vect *vect);
	void sub(const Vect *vect);
	void sqr();
	float sum();
	Vect* multiplyR(const Mat *mat) const;
	Vect* multiplyC(const Mat *mat) const;
	Mat* multiplyRC(const Vect *vect) const;
	Mat* multiplyCR(const Vect *vect) const;


	void multiply(float f);

	Mat* toMatRow() const;
	Mat* toMatCol() const;

	void insert(float value, int pos=-1);

	void print() const;

	~Vect();
};


#endif

/*-- #include "neuralnets\NNLayer.h" start --*/
#ifndef NNLAYER_H
#define NNLAYER_H

class Mat;
class Vect;

const int NNL_ACT_FUN_NONE=0, NNL_ACT_FUN_RELU=1, NNL_ACT_FUN_SIGMOID=2, NNL_ACT_FUN_SOFTMAX=3, NNL_ACT_FUN_TANHYP=4, NNL_ACT_FUN_UNDEF=99;

class NNLayer
{
	int num_input;
	int num_output;
	Mat *w;
	Vect *b;
	Vect *_z;
	Vect *_x;
	int act_fun;

public:

	NNLayer(int num_input, int num_output) : NNLayer(num_input, num_output, NNL_ACT_FUN_NONE) {}
	NNLayer(int num_input, int num_output, int activation_function);

	void setActivationFunction(int activation_function);

	Vect* forwardPropagate(const Vect* input);
	Vect* backwardPropagate(const Vect *e, float lr);

	int getNumInput() const;
	int getNumOutput() const;

	void print() const;

	Mat* getWeights() const;
	Vect* getBiases() const;

	~NNLayer();
};


#endif  // NNLAYER_H

/*-- #include "neuralnets\NN.h" start --*/
#ifndef NN_H
#define NN_H

class Vect;
class NNLayer;

class NN
{
	int num_input;
	int num_layers;
	NNLayer **layers;

public:

	NN(int num_input);
	void addLayer(int num_output);

	int getNumLayers()  const;
	NNLayer* getLayer(int n)  const;

	int getNumInput() const;
	int getNumOutput() const;

	Vect* forwardPropagate(const Vect *input);
	Vect* backwardPropagate(const Vect *expected_output, const Vect *last_output, float learning_rate);

	void print() const;

	void init_car_race_net();
	void init_car_race_netZERO();
	void init_car_race_netTEST();

	~NN();
};


#endif  // NNLAYER_H

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H

#include <stdio.h>



NN::NN(int num_input) {
	this->num_input = num_input;
	this->num_layers = 0;
	this->layers = 0;
}

int NN::getNumLayers() const {
	return num_layers;
}

NNLayer* NN::getLayer(int n) const {
	return layers[n];
}

void NN::addLayer(int num_output) {
	int old_output = getNumOutput();
	if (num_layers == 0) {
		layers = new NNLayer*[1];
	}
	else {
		NNLayer **old_layers = layers;
		layers = new NNLayer*[num_layers+1];
		for (int i=0; i<num_layers; i++) {
			layers[i] = old_layers[i];
		}
		delete old_layers;
	}
	layers[num_layers] = new NNLayer(old_output, num_output);
	num_layers = num_layers + 1;
}


int NN::getNumInput() const {
	return num_input;
}

int NN::getNumOutput() const {
	if (num_layers == 0) {
		return getNumInput();
	}
	return layers[num_layers-1]->getNumOutput();
}

Vect* NN::forwardPropagate(const Vect *input) {
	if (num_layers == 0) {
		Vect *result = new Vect(input);
		return result;
	}
	Vect *result = (Vect *)input;
	Vect* tempResult = 0;
	for (int i=0; i<num_layers; i++) {
		result = layers[i]->forwardPropagate(result);
		if (tempResult != 0) {
			delete tempResult;
		}
		tempResult = result;
	}
	return result;
}

Vect* NN::backwardPropagate(const Vect *expected_output, const Vect *last_output, float learning_rate) {
	Vect *err = new Vect(last_output);
	err->sub(expected_output);
	for (int n=num_layers-1; n>=0; n--) {
		NNLayer *layer = layers[n];
		Vect *err_in = layer->backwardPropagate(err, learning_rate);
		delete err;
		err = err_in;
	}
	return err;
}



void NN::print() const {
	char buf[32];
	sprintf(buf, "NN(%d)\r\n", num_layers);
	log(buf);
	for (int i=0; i<num_layers; i++) {
		layers[i]->print();
	}
}

//static const float car_race_net_weights12TEST[2][3] = {
//		{-0.19054012,  0.75732634, -0.82117337},
//		{-0.44180573, -0.52005017, -0.61912042}
//};
//static const float car_race_net_biases12TEST[3] = {
//		-0.67861546, -0.56278163, -0.50019205
//};
//static const float car_race_net_weights23TEST[3][2] = {
//		{-0.17790172,  0.08958844},
//        { 0.26170852, -0.50326608},
//        { 0.56101698, -0.76496092}
//};
//static const float car_race_net_biases23TEST[2] = {
//		0.09764059, 0.10069135
//};
static const float car_race_net_weights12TEST[2][1] = {
		{-0.35088017},
		{ 0.47722959}
};
static const float car_race_net_biases12TEST[1] = {
		-1.55983051
};
static const float car_race_net_weights23TEST[1][2] = {
		{-0.31765768, -1.03063498}
};
static const float car_race_net_biases23TEST[2] = {
		-0.87784716, -0.61996188
};


static const float car_race_net_weights12[6][10] = {
   { 2.92982598, -2.59533988,  1.68390812, -6.45044018,  2.21847395,
	 9.09846116,  2.09019814,  7.47994636, -1.55154732,  4.053405  },
   {-0.13951569,  0.16532004,  0.35031744, -0.14538902, -0.14230515,
	-0.04077859,  0.06114672,  0.56549284, -0.98225385, -0.24975129},
   { 1.3779408 , -0.65626776,  0.72276261,  0.91624962,  1.02740159,
	 0.85154398, -1.16521592, -0.7208113 , -6.0999097 ,  0.50902216},
   { 4.94442865,  1.16562836,  0.67292358,  1.8444296 , -0.84909359,
	-0.38658771, -0.68875699, -3.23481914, -4.54541425,  1.73644381},
   { 0.34283657,  3.49122586, -1.07141273,  0.30191829,  1.88195363,
	 1.18214337, -5.25065642, -1.5788444 ,  2.81243613,  1.36685535},
   {-0.05290731, -0.36936821, -1.37291634,  0.35314155,  0.65418381,
	-0.15870702, -0.05026738,  0.27220292,  2.65996218, -0.21896395}
};
static const float car_race_net_weights12ZERO[6][10] = {
  { 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
};


static const float car_race_net_biases12[10] = {
   -3.80692954, -0.99609635, -0.760793  ,  3.34655166, -1.14131986,
   -5.14198978,  2.46194382, -3.65475694,  0.59807103, -2.08264843
};
static const float car_race_net_biases12ZERO[10] = {
	0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0,
};



static const float car_race_net_weights23[10][10] = {
   {-2.95089874e+00,  6.33863210e+00, -5.64784825e-01,
	-1.34862174e-01,  6.32867453e+00, -6.93072053e+00,
	-2.76446263e+00, -4.28698039e+00, -8.03317104e-01,
	 2.76539314e+00},
   { 5.79895095e-01, -9.19510015e+00,  2.33771386e-01,
	 1.32312884e+01,  8.54901934e+00, -5.56905363e-01,
	 3.37500716e+00,  5.79642971e+00,  3.14798403e-01,
	-3.59972036e+00},
   {-1.14265946e+00, -1.35520658e+01, -5.36028785e-03,
	-2.94413770e+00,  4.46875500e+00,  7.85978839e+00,
	-3.05620140e+00,  9.21020632e-01,  1.51585913e-01,
	 3.61368181e+00},
   { 6.45857555e+00, -6.01469394e-01, -1.03160308e+00,
	-2.60155781e+00,  3.66358923e+00,  2.74846385e+00,
	 5.31858144e+00,  1.76314377e+01,  7.10212466e-02,
	-1.06319317e+01},
   {-1.97276685e+00, -2.15927960e+00,  4.15142518e-01,
	-4.21676472e+00,  1.79578768e+00,  8.45763920e+00,
	-6.76088439e+00, -1.40965105e+00, -4.85121956e-02,
	-1.56227099e+00},
   { 3.36960513e+00, -1.44461726e+00, -3.94443030e+00,
	-6.36305430e+00,  1.51471980e-01,  1.15357224e+01,
	-7.88027186e+00,  6.98760934e-01, -1.19283372e+00,
	-4.80561946e+00},
   { 1.26324526e+00, -8.79875175e+00, -1.57579062e+00,
	 9.10906053e+00,  5.52157045e+00,  7.09297928e+00,
	-8.06926747e+00,  5.86703321e+00, -5.09300852e-02,
	-3.98477665e+00},
   { 3.69880541e+00, -1.12316158e+00,  1.35547589e+00,
	 4.70517062e+00,  1.13739045e+01,  6.11269490e+00,
	 6.92073105e+00,  4.49550849e+00,  1.02886093e-01,
	-2.70772383e+00},
   { 2.51334232e-01, -1.13002334e+01, -4.16675575e-01,
	-8.07980143e-01, -4.43702092e-02, -9.85902553e-01,
	 1.04786543e+00,  5.12631959e-01, -2.84400132e-01,
	 1.98691284e+00},
   { 3.52555263e+00,  1.71847070e+01,  3.62415484e+00,
	-6.37929472e+00,  3.25595435e+00, -2.43483794e+00,
	 1.65547364e+00,  3.05531071e+00,  1.97123054e+00,
	-2.17144239e+00}
};
static const float car_race_net_weights23ZERO[10][10] = {
  { 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0 },
};

static const float car_race_net_biases23[10] = {
	-2.57641358,   5.22974549,   0.18196597,   3.55930069,
	 7.76041084, -10.3746859 ,   5.17933678, -14.01284557,
	 0.27489897,   0.22506589
};
static const float car_race_net_biases23ZERO[10] = {
	1.0, -0.1, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0,
};


static const float car_race_net_weights34[10][3] = {
   {  0.30475765,  -3.72432552,   2.89807721},
   {  2.47523919,  -0.07113565,  -2.34002766},
   {  6.47865935,  -3.58909989,  -4.11516189},
   { -7.46690826,   2.18849342,   5.37326228},
   {  1.69779199,  -2.94359089,   0.5098125 },
   {  2.33500901,  -2.59166875,   0.43530021},
   {  1.29487568,  -2.89745911,   0.87452631},
   {  1.37053505,   1.68520382,  -2.80015337},
   {-12.1493566 ,   3.98479873,   9.31744796},
   { -3.46432305,  -2.00026348,   3.62938781}
};
static const float car_race_net_weights34ZERO[10][3] = {
  { 1.0, 2.0, 1.0 },
  { 1.0, 2.0, 1.0 },
  { 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0 },
  { 0.0, 0.0, 0.0 },
};

static const float car_race_net_biases34[3] = {
  -3.91892902, -3.24655446,  6.87568216
};
static const float car_race_net_biases34ZERO[3] = {
  0.0, 0.0, 0.0,
};



void set_weights(Mat* weights, float* data) {
	for (int r=0; r<weights->getRows(); r++) {
		for (int c=0; c<weights->getCols(); c++) {
			weights->set(r, c, *data);
			data++;
		}
	}
//	for (int c=0; c<weights->getCols(); c++) {
//		for (int r=0; r<weights->getRows(); r++) {
//			weights->set(r, c, *data);
//			data++;
//		}
//	}
}

void set_biases(Vect* biases, float* data) {
	for (int i=0; i<biases->getLength(); i++) {
		biases->set(i, *data);
		data++;
	}
}


void NN::init_car_race_net() {
	set_weights(layers[0]->getWeights(), (float*) car_race_net_weights12);
	set_biases(layers[0]->getBiases(), (float*) car_race_net_biases12);
	set_weights(layers[1]->getWeights(), (float*) car_race_net_weights23);
	set_biases(layers[1]->getBiases(), (float*) car_race_net_biases23);
	set_weights(layers[2]->getWeights(), (float*) car_race_net_weights34);
	set_biases(layers[2]->getBiases(), (float*) car_race_net_biases34);
}


void NN::init_car_race_netZERO() {
	set_weights(layers[0]->getWeights(), (float*) car_race_net_weights12ZERO);
	set_biases(layers[0]->getBiases(), (float*) car_race_net_biases12ZERO);
	set_weights(layers[1]->getWeights(), (float*) car_race_net_weights23ZERO);
	set_biases(layers[1]->getBiases(), (float*) car_race_net_biases23ZERO);
	set_weights(layers[2]->getWeights(), (float*) car_race_net_weights34ZERO);
	set_biases(layers[2]->getBiases(), (float*) car_race_net_biases34ZERO);
}


void NN::init_car_race_netTEST() {
	set_weights(layers[0]->getWeights(), (float*) car_race_net_weights12TEST);
	set_biases(layers[0]->getBiases(), (float*) car_race_net_biases12TEST);
	set_weights(layers[1]->getWeights(), (float*) car_race_net_weights23TEST);
	set_biases(layers[1]->getBiases(), (float*) car_race_net_biases23TEST);
}


NN::~NN() {
	for (int i=0; i<num_layers; i++) {
		delete layers[i];
	}
	num_layers = 0;
	delete layers;
	layers = 0;
}


/*-- File: neuralnets\NN.cpp end --*/
/*-- #include "neuralnets\NN.h" start --*/
#ifndef NN_H
#define NN_H

class Vect;
class NNLayer;

class NN
{
	int num_input;
	int num_layers;
	NNLayer **layers;

public:

	NN(int num_input);
	void addLayer(int num_output);

	int getNumLayers()  const;
	NNLayer* getLayer(int n)  const;

	int getNumInput() const;
	int getNumOutput() const;

	Vect* forwardPropagate(const Vect *input);
	Vect* backwardPropagate(const Vect *expected_output, const Vect *last_output, float learning_rate);

	void print() const;

	void init_car_race_net();
	void init_car_race_netZERO();
	void init_car_race_netTEST();

	~NN();
};


#endif  // NNLAYER_H

/*-- File: neuralnets\NNLayer.cpp start --*/
/*-- #include "neuralnets\Mat.h" start --*/
#ifndef MAT_H
#define MAT_H

class Vect;

class Mat
{
	int     nRows;
	int     nCols;
	float   *data;

public:

	Mat(int rows, int cols);
	Mat(const Mat *mat);
	Mat(const Mat& mat);
	Mat(int rows, int cols, const float *data);
	int getCols() const;
	int getRows() const;
	float get(int row, int col) const;
	void set(int row, int col, float v);
	Mat* transpose();

	void add(const Mat *mat);
	void sub(const Mat *mat);

	Mat* multiply(Mat *mat);
	Mat* multiplyT(Mat *mat);

	void multiply(float f);

	void addR(Vect *vect);
	void addC(Vect *vect);

	void print() const;

	~Mat();
};

#endif

/*-- #include "neuralnets\Vect.h" start --*/
#ifndef VECT_H
#define VECT_H

class Mat;

class Vect
{
	int     length;
	float   *data;

public:

	Vect(int length);
	Vect(int length, const float* data);
	Vect(const Vect *vect);
	Vect(const Vect& vect);
	Vect(const Mat *mat);
	int getLength() const;
	float get(int n) const;
	void set(int n, float v);
	void multiply(const Vect *vect);
	void add(const Vect *vect);
	void sub(const Vect *vect);
	void sqr();
	float sum();
	Vect* multiplyR(const Mat *mat) const;
	Vect* multiplyC(const Mat *mat) const;
	Mat* multiplyRC(const Vect *vect) const;
	Mat* multiplyCR(const Vect *vect) const;


	void multiply(float f);

	Mat* toMatRow() const;
	Mat* toMatCol() const;

	void insert(float value, int pos=-1);

	void print() const;

	~Vect();
};


#endif

/*-- #include "neuralnets\NNLayer.h" start --*/
#ifndef NNLAYER_H
#define NNLAYER_H

class Mat;
class Vect;

const int NNL_ACT_FUN_NONE=0, NNL_ACT_FUN_RELU=1, NNL_ACT_FUN_SIGMOID=2, NNL_ACT_FUN_SOFTMAX=3, NNL_ACT_FUN_TANHYP=4, NNL_ACT_FUN_UNDEF=99;

class NNLayer
{
	int num_input;
	int num_output;
	Mat *w;
	Vect *b;
	Vect *_z;
	Vect *_x;
	int act_fun;

public:

	NNLayer(int num_input, int num_output) : NNLayer(num_input, num_output, NNL_ACT_FUN_NONE) {}
	NNLayer(int num_input, int num_output, int activation_function);

	void setActivationFunction(int activation_function);

	Vect* forwardPropagate(const Vect* input);
	Vect* backwardPropagate(const Vect *e, float lr);

	int getNumInput() const;
	int getNumOutput() const;

	void print() const;

	Mat* getWeights() const;
	Vect* getBiases() const;

	~NNLayer();
};


#endif  // NNLAYER_H

/*-- #include "neuralnets\NNUtils.h" start --*/
#ifndef NNUTILS_H
#define NNUTILS_H

class Vect;
class Mat;

void initRand();

void fillRandomNorm(Mat* mat, float from, float to);
void fillRandomNorm(Vect* vect, float from, float to);

void fillRandom(Mat* mat, float from, float to);
void fillRandom(Vect* vect, float from, float to);

void fill(Vect* vect, float v);
void fill(Mat* mat, float v);

float relu(float f);
void relu(Vect *vect);

float sigmoid(float f);
void sigmoid(Vect *vect);

float tanhyp(float f);
void tanhyp(Vect *vect);

void softmax(Vect *vect);

float relu_prime(float f);
void relu_prime(Vect *vect);

Vect createVect(int length, ...);
Mat createMat(int rows, int cols, ...);

#endif // NNUTILS_H

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H

#include <stdio.h>
#include <math.h>


NNLayer::NNLayer(int num_input, int num_output, int activation_function) {
	this->num_input = num_input;
	this->num_output = num_output;
	w = new Mat(num_input, num_output);
	fillRandomNorm(w, -1.0f, 1.0f);
	w->multiply(sqrt(2.0f/num_input));
	b = new Vect(num_output);
	fill(b, 0.1f);
	_x = 0;
	_z = 0;
	act_fun = activation_function;
}

void NNLayer::setActivationFunction(int activation_function) {
	act_fun = activation_function;
}

int NNLayer::getNumInput() const {
	return num_input;
}

int NNLayer::getNumOutput() const {
	return num_output;
}


Vect* NNLayer::forwardPropagate(const Vect *x) {
	if (_x != 0) {
		delete _x;
		delete _z;
	}
	_x = new Vect(x);
	_z = x->multiplyC(w);
//log("MULTIPLY x*W = ");
//_z->print();
	_z->add(b);
//log("MULTIPLY x*W+b = ");
//_z->print();
	Vect *result = new Vect(_z);

	switch(act_fun) {
		case NNL_ACT_FUN_NONE:
			break;
		case NNL_ACT_FUN_RELU:
			relu(result);
			break;
		case NNL_ACT_FUN_SIGMOID:
			sigmoid(result);
			break;
		case NNL_ACT_FUN_SOFTMAX:
			softmax(result);
			break;
		case NNL_ACT_FUN_TANHYP:
			tanhyp(result);
			break;
	}

//log("ACT:");
//logInt(act_fun);
//result->print();
	return result;
}

Vect* NNLayer::backwardPropagate(const Vect *e, float lr) {
	if (_z == 0) {
		print();
		throwError("calling backProp without haveing called forwardProp.");
	}
	Vect *e_zrp = new Vect(_z);
	relu_prime(e_zrp);
	e_zrp->multiply(e);
	Mat *dw = e_zrp->multiplyCR(_x);
	dw->multiply(lr);
	w->sub(dw);
	Vect* e_in = e->multiplyR(w);
	delete e_zrp;
	delete dw;
	return e_in;
}

void NNLayer::print() const {
	char buf[64];
	const char*act;
	switch (act_fun) {
	case NNL_ACT_FUN_NONE:
		act="";
		break;
	case NNL_ACT_FUN_RELU:
		act="act=relu";
		break;
	case NNL_ACT_FUN_SIGMOID:
		act="act=sigmoid";
		break;
	case NNL_ACT_FUN_SOFTMAX:
		act="act=softmax";
		break;
	case NNL_ACT_FUN_TANHYP:
		act="act=tanh";
		break;
	default:
		act = "act=???";
	}
	sprintf(buf, "NNLayer(%d, %d) %s\r\n", num_input, num_output, act);
	log(buf);
	w->print();
	b->print();
}


Mat* NNLayer::getWeights() const {
	return w;
}

Vect* NNLayer::getBiases() const {
	return b;
}


NNLayer::~NNLayer() {
	if (_x != 0) {
		delete _x;
		delete _z;
		_x=0;
		_z=0;
	}
	delete w;
	delete b;
	w = 0;
	b = 0;
}

/*-- File: neuralnets\NNLayer.cpp end --*/
/*-- #include "neuralnets\NNLayer.h" start --*/
#ifndef NNLAYER_H
#define NNLAYER_H

class Mat;
class Vect;

const int NNL_ACT_FUN_NONE=0, NNL_ACT_FUN_RELU=1, NNL_ACT_FUN_SIGMOID=2, NNL_ACT_FUN_SOFTMAX=3, NNL_ACT_FUN_TANHYP=4, NNL_ACT_FUN_UNDEF=99;

class NNLayer
{
	int num_input;
	int num_output;
	Mat *w;
	Vect *b;
	Vect *_z;
	Vect *_x;
	int act_fun;

public:

	NNLayer(int num_input, int num_output) : NNLayer(num_input, num_output, NNL_ACT_FUN_NONE) {}
	NNLayer(int num_input, int num_output, int activation_function);

	void setActivationFunction(int activation_function);

	Vect* forwardPropagate(const Vect* input);
	Vect* backwardPropagate(const Vect *e, float lr);

	int getNumInput() const;
	int getNumOutput() const;

	void print() const;

	Mat* getWeights() const;
	Vect* getBiases() const;

	~NNLayer();
};


#endif  // NNLAYER_H

/*-- File: neuralnets\NNUtils.cpp start --*/
#ifndef NNUTILS_H
#define NNUTILS_H

/*-- #include "neuralnets\Vect.h" start --*/
#ifndef VECT_H
#define VECT_H

class Mat;

class Vect
{
	int     length;
	float   *data;

public:

	Vect(int length);
	Vect(int length, const float* data);
	Vect(const Vect *vect);
	Vect(const Vect& vect);
	Vect(const Mat *mat);
	int getLength() const;
	float get(int n) const;
	void set(int n, float v);
	void multiply(const Vect *vect);
	void add(const Vect *vect);
	void sub(const Vect *vect);
	void sqr();
	float sum();
	Vect* multiplyR(const Mat *mat) const;
	Vect* multiplyC(const Mat *mat) const;
	Mat* multiplyRC(const Vect *vect) const;
	Mat* multiplyCR(const Vect *vect) const;


	void multiply(float f);

	Mat* toMatRow() const;
	Mat* toMatCol() const;

	void insert(float value, int pos=-1);

	void print() const;

	~Vect();
};


#endif

/*-- #include "neuralnets\Mat.h" start --*/
#ifndef MAT_H
#define MAT_H

class Vect;

class Mat
{
	int     nRows;
	int     nCols;
	float   *data;

public:

	Mat(int rows, int cols);
	Mat(const Mat *mat);
	Mat(const Mat& mat);
	Mat(int rows, int cols, const float *data);
	int getCols() const;
	int getRows() const;
	float get(int row, int col) const;
	void set(int row, int col, float v);
	Mat* transpose();

	void add(const Mat *mat);
	void sub(const Mat *mat);

	Mat* multiply(Mat *mat);
	Mat* multiplyT(Mat *mat);

	void multiply(float f);

	void addR(Vect *vect);
	void addC(Vect *vect);

	void print() const;

	~Mat();
};

#endif


#include<stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void initRand() {
	 time_t t;
	 srand((unsigned) time(&t));
	 rand(); rand(); rand();
}

void fillRandom(Mat* mat, float from, float to) {
	float diff = to-from;
	int maxR = mat->getRows();
	int maxC = mat->getCols();
	for (int r=0; r<maxR; r++) {
		for (int c=0; c<maxC; c++) {
			float v = ((float) (rand() % 1001))/1001.0f;
			float vRange = from+diff*v;
			mat->set(r, c, vRange);
		}
	}
}

void fillRandom(Vect* vect, float from, float to) {
	float diff = to-from;
	for (int i=0; i<vect->getLength(); i++) {
		float v = ((float) (rand() % 1001))/1001.0f;
		float vRange = from+diff*v;
		vect->set(i, vRange);
	}
}

void fillRandomNorm(Mat* mat, float from, float to) {
	float diff = to-from;
	int maxR = mat->getRows();
	int maxC = mat->getCols();
	for (int r=0; r<maxR; r++) {
		for (int c=0; c<maxC; c++) {
			float v = ((float) ((rand() % 1001)+(rand() % 1001)+(rand() % 1001)))/3003.0;
			float vRange = from+diff*v;
			mat->set(r, c, vRange);
		}
	}
}

void fillRandomNorm(Vect* vect, float from, float to) {
	float diff = to-from;
	for (int i=0; i<vect->getLength(); i++) {
		float v = ((float) ((rand() % 1001)+(rand() % 1001)+(rand() % 1001)))/3003.0;
		float vRange = from+diff*v;
		vect->set(i, vRange);
	}
}


void fill(Vect* vect, float v) {
	for (int i=0; i<vect->getLength(); i++) {
		vect->set(i, v);
	}
}

void fill(Mat* mat, float v) {
	for (int r=0; r<mat->getRows(); r++) {
		for (int c=0; c<mat->getRows(); r++) {
			mat->set(r,c, v);
		}
	}
}


float relu(float f) {
	if (f<0.0f) {
		return 0.0f;
	}
	return f;
}

void relu(Vect *vect) {
	for (int i=0; i<vect->getLength(); i++) {
		vect->set(i, relu(vect->get(i)));
	}
}

float tanhyp(float f) {
	return tanh(f);
}

void tanhyp(Vect *vect) {
	for (int i=0; i<vect->getLength(); i++) {
		vect->set(i, tanhyp(vect->get(i)));
	}
}

float sigmoid(float f) {
	return 1/(1+pow(2.71828182845905f, -f));
}

void sigmoid(Vect *vect) {
	for (int i=0; i<vect->getLength(); i++) {
		vect->set(i, sigmoid(vect->get(i)));
	}
}

void softmax(Vect *vect) {
	float sum = 0.0f;
	for (int i=0; i<vect->getLength(); i++) {
		float exp = pow(2.71828182845905f, vect->get(i));
		sum = sum + exp;
		vect->set(i, exp);
	}
	if (sum != 0.0f) {
		for (int i=0; i<vect->getLength(); i++) {
			vect->set(i, vect->get(i)/sum);
		}
	}
}

float relu_prime(float f) {
	if (f<0.0f) {
		return 0.0f;
	}
	return 1.0f;
}

void relu_prime(Vect *vect) {
	for (int i=0; i<vect->getLength(); i++) {
		vect->set(i, relu_prime(vect->get(i)));
	}
}

Vect createVect(int length, ...) {
	va_list argp;
	va_start(argp, length);
	Vect result = Vect(length);
	for (int i=0; i<length; i++) {
		float f = va_arg(argp, double);
		result.set(i, f);
	}
	va_end(argp);
	return result;
}

Mat createMat(int rows, int cols, ...) {
	va_list argp;
	va_start(argp, cols);
	Mat result = Mat(rows, cols);
	for (int r=0; r<rows; r++) {
		for (int c=0; c<cols; c++) {
			float f = va_arg(argp, double);
			result.set(r,c, f);
		}
	}
	va_end(argp);
	return result;
}





#endif // NNUTILS_H

/*-- File: neuralnets\NNUtils.cpp end --*/
/*-- #include "neuralnets\NNUtils.h" start --*/
#ifndef NNUTILS_H
#define NNUTILS_H

class Vect;
class Mat;

void initRand();

void fillRandomNorm(Mat* mat, float from, float to);
void fillRandomNorm(Vect* vect, float from, float to);

void fillRandom(Mat* mat, float from, float to);
void fillRandom(Vect* vect, float from, float to);

void fill(Vect* vect, float v);
void fill(Mat* mat, float v);

float relu(float f);
void relu(Vect *vect);

float sigmoid(float f);
void sigmoid(Vect *vect);

float tanhyp(float f);
void tanhyp(Vect *vect);

void softmax(Vect *vect);

float relu_prime(float f);
void relu_prime(Vect *vect);

Vect createVect(int length, ...);
Mat createMat(int rows, int cols, ...);

#endif // NNUTILS_H

/*-- File: neuralnets\Vect.cpp start --*/
/*-- #include "neuralnets\Vect.h" start --*/
#ifndef VECT_H
#define VECT_H

class Mat;

class Vect
{
	int     length;
	float   *data;

public:

	Vect(int length);
	Vect(int length, const float* data);
	Vect(const Vect *vect);
	Vect(const Vect& vect);
	Vect(const Mat *mat);
	int getLength() const;
	float get(int n) const;
	void set(int n, float v);
	void multiply(const Vect *vect);
	void add(const Vect *vect);
	void sub(const Vect *vect);
	void sqr();
	float sum();
	Vect* multiplyR(const Mat *mat) const;
	Vect* multiplyC(const Mat *mat) const;
	Mat* multiplyRC(const Vect *vect) const;
	Mat* multiplyCR(const Vect *vect) const;


	void multiply(float f);

	Mat* toMatRow() const;
	Mat* toMatCol() const;

	void insert(float value, int pos=-1);

	void print() const;

	~Vect();
};


#endif

/*-- #include "neuralnets\Mat.h" start --*/
#ifndef MAT_H
#define MAT_H

class Vect;

class Mat
{
	int     nRows;
	int     nCols;
	float   *data;

public:

	Mat(int rows, int cols);
	Mat(const Mat *mat);
	Mat(const Mat& mat);
	Mat(int rows, int cols, const float *data);
	int getCols() const;
	int getRows() const;
	float get(int row, int col) const;
	void set(int row, int col, float v);
	Mat* transpose();

	void add(const Mat *mat);
	void sub(const Mat *mat);

	Mat* multiply(Mat *mat);
	Mat* multiplyT(Mat *mat);

	void multiply(float f);

	void addR(Vect *vect);
	void addC(Vect *vect);

	void print() const;

	~Mat();
};

#endif

/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H

#include <stdio.h>


Vect::Vect(int length)
{
	this->length = length;
	data = new float[length];
}

Vect::Vect(const Vect *vect)
{
	this->length = vect->length;
	data = new float[length];
	for (int i = 0; i < length; i++)
		data[i] = vect->data[i];
}

Vect::Vect(int length, const float* data) {
	this->length = length;
	this->data = new float[length];
	for (int i = 0; i < length; i++)
		this->data[i] = data[i];
}

Vect::Vect(const Vect& copyVect)
{
	this->length = copyVect.getLength();
	data = new float[length];
	for (int i = 0; i < length; i++)
		data[i] = copyVect.data[i];
}

Vect::Vect(const Mat *mat)
{
	if (mat->getRows() == 1) {
		length = mat->getCols();
		data = new float[length];
		for (int i = 0; i < length; i++) {
			data[i] = mat->get(0, i);
		}
	}
	else if (mat->getCols() == 1) {
		length = mat->getRows();
		data = new float[length];
		for (int i = 0; i < length; i++) {
			data[i] = mat->get(i,0);
		}
	}
	else {
		print();
		mat->print();
		throwError("Vect::Vect: matrix has too many rows/cols");
	}
}

int Vect::getLength() const
{
	return length;
}

float Vect::get(int n) const
{
	if (n < 0 || n >= length) {
	    print();
		char buf[100];
		sprintf(buf, "\r\nn: %d\r\n", n);
		log(buf);
		throwError("Vect::get: index out of range");
	}
	return data[n];
}

void Vect::set(int n, float v)
{
	if (n < 0 || n >= length) {
	    print();
		char buf[100];
		sprintf(buf, "\r\nn: %d\r\n", n);
		log(buf);
		throwError("Vect::set: index out of range");
	}
	data[n] = v;
}

void Vect::multiply(const Vect *vect) {
	if (vect->length != length) {
		print();
		vect->print();
		throwError("Vect::multiply: langth mismatch");
	}
	for (int i = 0; i < length; i++)
	{
		set(i, get(i)*vect->get(i));
	}
}

void Vect::add(const Vect *vect) {
	if (vect->length != length) {
		print();
		vect->print();
		throwError("Vect::add: length mismatch");
	}
	for (int i = 0; i < length; i++)
	{
		set(i, get(i)+vect->get(i));
	}
}

void Vect::sub(const Vect *vect) {
	if (vect->length != length) {
		print();
		vect->print();
		throwError("Vect::sub: length mismatch");
	}
	for (int i = 0; i < length; i++)
	{
		set(i, get(i)-vect->get(i));
	}
}

void Vect::sqr() {
	for (int i = 0; i < length; i++)
	{
		set(i, get(i)*get(i));
	}
}

float Vect::sum() {
	float result = 0.0f;
	for (int i = 0; i < length; i++)
	{
		result += get(i);
	}
	return result;
}

Vect* Vect::multiplyR(const Mat *mat) const {
	if (mat->getCols() != length) {
		print();
		mat->print();
		throwError("Vect::multiplyC: length mismatch");
	}
	Vect *result = new Vect(mat->getRows());
	for (int r=0; r<mat->getRows(); r++) {
		float v=0;
		for (int i=0; i<length; i++) {
			v += get(i) * mat->get(r,i);
		}
		result->set(r, v);
	}
	return result;
}


Vect* Vect::multiplyC(const Mat *mat) const {
	if (mat->getRows() != length) {
		print();
		mat->print();
		throwError("Vect::multiplyR: length mismatch");
	}
	Vect *result = new Vect(mat->getCols());
	for (int c=0; c<mat->getCols(); c++) {
		float v=0;
		for (int i=0; i<length; i++) {
			v += get(i) * mat->get(i,c);
		}
		result->set(c, v);
	}
	return result;
}

Mat* Vect::multiplyCR(const Vect *vect) const {
	Mat* result = new Mat(vect->getLength(), getLength());
	for (int r=0; r<vect->getLength(); r++) {
		for (int c=0; c<getLength(); c++) {
			result->set(r,c, vect->get(r)*get(c));
		}
	}
	return result;
}


Mat* Vect::multiplyRC(const Vect *vect) const {
	Mat* result = new Mat(getLength(), vect->getLength());
	for (int r=0; r<getLength(); r++) {
		for (int c=0; c<vect->getLength(); c++) {
			result->set(r,c, get(r)*vect->get(c));
		}
	}
	return result;
}



void Vect::multiply(float f) {
	for (int i=0; i<length; i++) {
		set(i, get(i)*f);
	}
}


Mat* Vect::toMatRow() const {
	return new Mat(1, length, data);
}

Mat* Vect::toMatCol() const {
	return new Mat(length, 1, data);
}


void Vect::insert(float value, int pos) {
	if (pos == -1) {
		pos = length;
	}
	float *oldData = data;
	data = new float[length+1];
	for (int i=0; i<pos; i++) {
		data[i] = oldData[i];
	}
	data[pos] = value;
	for (int i=pos; i<length; i++) {
		data[i+1] = oldData[i];
	}
	length++;
	delete oldData;
}


void Vect::print() const {
	log("VECT\r\n");
	char buf[100];
	for (int i=0; i<length; i++) {
		float v = get(i);
		int len = float2char(buf, v, 4);
		for (int i=len; i<10; i++) {
			log(" ");
		}
		log(buf);
	}
	log("\r\n");
}


Vect::~Vect()
{
	delete data;
	data = 0;
}

/*-- File: neuralnets\Vect.cpp end --*/
/*-- #include "neuralnets\Vect.h" start --*/
#ifndef VECT_H
#define VECT_H

class Mat;

class Vect
{
	int     length;
	float   *data;

public:

	Vect(int length);
	Vect(int length, const float* data);
	Vect(const Vect *vect);
	Vect(const Vect& vect);
	Vect(const Mat *mat);
	int getLength() const;
	float get(int n) const;
	void set(int n, float v);
	void multiply(const Vect *vect);
	void add(const Vect *vect);
	void sub(const Vect *vect);
	void sqr();
	float sum();
	Vect* multiplyR(const Mat *mat) const;
	Vect* multiplyC(const Mat *mat) const;
	Mat* multiplyRC(const Vect *vect) const;
	Mat* multiplyCR(const Vect *vect) const;


	void multiply(float f);

	Mat* toMatRow() const;
	Mat* toMatCol() const;

	void insert(float value, int pos=-1);

	void print() const;

	~Vect();
};


#endif

/*-- File: platform\Utils.cpp start --*/


/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H


//#include<stdio.h>
#include<stdarg.h>
//#include<string.h>
//#include <math.h>
//#include <float.h>
//#include <iostream>


// from: https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/Print.cpp
size_t float2char(char* buf, float number, uint8_t digits) {
  size_t n = 0;

  if (isnan(number)) return sprintf(buf, "nan");
  if (isinf(number)) return sprintf(buf, "inf");
  if(number > 4294967040.0) {
      return sprintf(buf, "ovf");    // constant determined empirically
  }
  if(number < -4294967040.0) {
      return sprintf(buf, "ovf");    // constant determined empirically
}

  // Handle negative numbers
  if (number < 0.0)
  {
     n += sprintf((char*)(buf+n), "-");
     number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  float rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i)
    rounding /= 10.0;

  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  n += sprintf((char*)(buf+n), "%lu", int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0) {
    n += sprintf((char*)(buf+n), ".");
  }

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    int toPrint = int(remainder);
    n += sprintf((char*)(buf+n), "%d",toPrint);
    remainder -= toPrint;
  }

  return n;
}

#define SEC_PREFIX 		0
#define SEC_INTPART 	1
#define SEC_FRAGPART 	2
#define SEC_EXPPREFIX 	3
#define SEC_EXP 		4
#define SEC_FINISHED 	99

// after calling atof("4.7452347e-316") the program gets stuck some times later.
// so, use an own char2float() method instead of atof().
//
// Example: -12.34e+03
// Section: 011 22 344
//
float char2float(const char* text) {
	bool neg = false;
	bool negexp = false;
	float result = 0;
	float decpos = 0.1;
	float exp = 0;
	const char* pc = text;
	int section = SEC_PREFIX;
	while ((section != SEC_FINISHED) && (*pc)) {
		char c = *pc++;
		switch (section) {
		case SEC_PREFIX:
			if (c == '-') {
				neg = true;
			}
			else if (c == '+') {
				neg = false;
			}
			else {
				pc--;
			}
			section = SEC_INTPART;
			break;
		case SEC_INTPART:
			if (c == '.') {
				section = SEC_FRAGPART;
			}
			else if ((c == 'e') || (c == 'E')) {
				section = SEC_EXPPREFIX;
			}
			else if ((c >= '0') && (c <= '9')) {
				result = result*10 + (c-'0');
			}
			else {
				section = SEC_FINISHED;
			}
			break;
		case SEC_FRAGPART:
			if ((c == 'e') || (c == 'E')) {
				section = SEC_EXPPREFIX;
			}
			else if ((c >= '0') && (c <= '9')) {
				result = result + (decpos*(c-'0'));
				decpos = decpos / 10;
			}
			else {
				section = SEC_FINISHED;
			}
			break;
		case SEC_EXPPREFIX:
			if (c == '+') {
				negexp = false;
				section = SEC_EXP;
			}
			else if (c == '-') {
				negexp = true;
				section = SEC_EXP;
			}
			else {
				section = SEC_FINISHED;
			}
			break;
		case SEC_EXP:
			if ((c >= '0') && (c <= '9')) {
				exp = exp*10 + (c-'0');
			}
			else {
				section = SEC_FINISHED;
			}
			break;
		default:
			section = SEC_FINISHED;
			break;
		}
	}
	if (negexp) {
		exp = -exp;
	}
	while (exp > 0) {
		result = result*10;
		exp--;
	}
	while (exp < 0) {
		result = result/10;
		exp++;
	}
	if (neg) {
		result = -result;
	}
	return result;
}


void throwError(const char *errMsg) {
	while (true) {
	    uBit.serial.send(errMsg);
		uBit.display.scroll(errMsg);
        uBit.sleep(1000);
        if ( uBit.buttonA.isPressed() == true ) {
        	uBit.sleep(24*60*60*1000);
        }
	}
}

void log(const char *msg) {
//	uBit.display.scroll(msg);
    uBit.serial.send(msg);
}

void logFloat(float f) {
	char buf[100];
	float2char(buf, f, 3);
	log(buf);
}

void logInt(int i) {
	char buf[100];
	sprintf(buf, "%d", i);
	log(buf);
}

/*-- File: platform\Utils.cpp end --*/
/*-- #include "platform\Utils.h" start --*/
#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

size_t float2char(char* buf, float number, uint8_t digits);
float char2float(const char* buf);

void throwError(const char *errMsg);

void log(const char *msg);
void logFloat(float f);
void logInt(int i);


#endif // UTILS_H

