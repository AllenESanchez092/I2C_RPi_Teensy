#include <Wire.h> // esta libreria permite la comunicacion i2c

#define Esclavo 0x2f //direccion a utilizar para la comunicacion

byte dim_datos_envio = 10;
byte datos_envio[dim_datos_envio] = {1,2,3,4,5,6,7,8,9,10};

byte dim_num_recibidos = 6;
byte datos_recibidos[dim_num_recibidos];

void setup()
{
	Serial.begin(115200);//configuracion de baudios
	Wire.begin(Esclavo); //direccion para el maestro!
	Wire.onRequest(EnviarDatos); // funcion utilizada por el maestro para pedir datos "Callback!"
	Wire.onReceive(RecibirDatos); // funcion para recibir datos
	pinMode(13,OUTPUT);
	digitalWrite(13,1);//enciende led para visualizar fisicamente
}

void loop()
{
	//aqui no va nada
}

//DEFINICION DE CALLBACKS:

void RecibirDatos(int NumeroBytes)
{
	while(Wire.available())//mientras haya datos
	{
		for(int NumeroDato; NumeroDato < NumeroBytes; NumeroDato++)
		{
			if(NumeroDato < dim_num_recibidos)
			{
				datos_recibidos[NumeroDato] = Wire.read();//se guardan los datos recibidos!
			}
			else//De otra manera se desechan!
			{
				Wire.read();
			}
		}
		//Impresion de datos:
		Serial.print("reservado: ");
		Serial.print(datos_recibidos[0]);
		Serial.print(" ");
		Serial.print("datos_recibidos: ");
		Serial.print(" ");
		Serial.print(datos_recibidos[1]);
		Serial.print(" ");
		Serial.print(datos_recibidos[2]);
		Serial.print(" ");
		Serial.print(datos_recibidos[3]);
		Serial.print(" ");
		Serial.print(datos_recibidos[4]);
		Serial.print(" ");
		Serial.println(datos_recibidos[5]);
	}
}

void EnviarDatos()
{
	Wire.write(datos_envio,dim_datos_envio);
}