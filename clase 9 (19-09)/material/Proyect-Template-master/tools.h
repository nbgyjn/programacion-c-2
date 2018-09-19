/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int ingresarInt(char mensaje[]);

/** \brief Solicita un numero entero al usuario y lo devuelve
 *
 * \param mensajeAMostrar[] char Mensaje a mostrar
 * \param mensajeError[] char Mensaje de error
 * \param lowLimit int Minimo permitido
 * \param hiLimit int Maximo permitido
 * \return int El numero validado.
 *
 */
int ingresarIntValido(char mensajeAMostrar[],char mensajeError[],int lowLimit, int hiLimit);

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float ingresarFloat(char mensaje[]);


/** \brief Solicita un numero flotante al usuario y lo devuelve
 *
 * \param mensajeAMostrar[] char Mensaje a mostrar
 * \param mensajeError[] char Mensaje de error
 * \param lowLimit float Minimo permitido
 * \param hiLimit float Maximo permitido
 * \return float El numero validado.
 *
 */
float ingresarFloatValido(char mensajeAMostrar[],char mensajeError[],float lowLimit, float hiLimit);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char ingresarChar(char mensaje[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void ingresarString(char mensaje[],char input[]);

/** \brief Solicita un texto que est� conformado s�lo por letras o " " y lo devuelve
 *
 * \param mensajeAMostrar[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje de error (Caracteres no permitidos)
 * \param mensajeErrorExced[] char Mensaje de error (Largo permitido excedido)
 * \param input[] char El string donde se guardar� el texto validado.
 * \param maxLenght int El parametro de longitud permitida.
 * \return void
 *
 */
void ingresarStringValida(char mensajeAMostrar[], char mensajeError[], char mensajeErrorExced[], char input[], int largoMax);


///////////////////////////////////////////////////////////////////////////////////////////
/** \brief Solicita un password conformado por numeros, letras y/o caracteres especiales y lo devuelve
 *
 * \param mensajeAMostrar[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje de error (Caracteres no permitidos)
 * \param mensajeErrorExced[] char Mensaje de error (Largo permitido excedido)
 * \param input[] char El string donde se guardar� el texto validado.
 * \param maxLenght int El parametro de longitud permitida.
 * \return void
 *
 */
void ingresarStringValidaPass(char mensajeAMostrar[], char mensajeError[], char mensajeErrorExced[], char input[], int largoMax);

/** \brief Solicita un telefono que est� conformado s�lo por numeros y un guion (-) y lo devuelve
 *
 * \param mensajeAMostrar[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje de error (Caracteres no permitidos)
 * \param mensajeErrorExced[] char Mensaje de error (Largo permitido excedido)
 * \param input[] char El string donde se guardar� el texto validado.
 * \param maxLenght int El parametro de longitud permitida.
 * \return void
 *
 */
void ingresarStringValidaTelefono(char mensajeAMostrar[], char mensajeError[], char mensajeErrorExced[], char input[], int largoMax);

/** \brief Solicita un texto que est� conformado s�lo por letras y/o numeros y lo devuelve
 *
 * \param mensajeAMostrar[] char Mensaje a mostrar.
 * \param mensajeError[] char Mensaje de error (Caracteres no permitidos)
 * \param mensajeErrorExced[] char Mensaje de error (Largo permitido excedido)
 * \param input[] char El string donde se guardar� el texto validado.
 * \param maxLenght int El parametro de longitud permitida.
 * \return void
 *
 */
void ingresarStringValidaAlfa(char mensajeAMostrar[], char mensajeError[], char mensajeErrorExced[], char input[], int largoMax);
////////////////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumerico(char str[]) ;

/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);
///////////////////////////////////////////////////////////////////////

/**
 * \brief Verifica si el valor recibido contiene letras, n�meros y/o caracteres especiales.
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esPass(char str[]);
//////////////////////////////////////////////////////////////////////
/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int ingresarStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int ingresarStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int ingresarStringLetras(char mensaje[],char input[]);

/////////////////////////////////////////////////////////////////////

/**
 * \brief Solicita un password al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int ingresarStringPass(char mensaje[],char input[]);

/**
 * \brief Solicita un telefono al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int ingresarStringTelefono(char mensaje[],char input[]);

/**
 * \brief Solicita un texto alfanumerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int ingresarStringAlfa(char mensaje[],char input[]);

/////////////////////////////////////////////////////////////////////


/** \brief Limpia el stdin, similar a fflush
 *
 * \param void
 * \return void
 *
 */
void clearStdin(void);

/** \brief Hace una pausa, similar al system("pause")
 *
 * \param void
 * \return void
 *
 */
void pause(void);

/** \brief Hace un clear, similar al system("clear")
 *
 * \param void
 * \return void
 *
 */
void clearScreen(void);

/** \brief Imprime un mensaje en pantalla seg�n el valor recibido.
 *
 * \param valor int El cod. de mensaje recibido.
 * \param error[] char Si el cod. es 0, se muestra un mensaje de error.
 * \param sucess[] char Si el cod. es 1, se muestra un mensaje de validacion.
 * \return void
 *
 */
void mensajeRetorno(int valor, char Mensaje1[], char Mensaje2[], char Mensaje3[]);
