#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief recibe dos numeros y calcula la suma de ellos.
 *
 * \param op1 corresponde al primer operando ingresado por el usuario.
 * \param op2 corresponde al segundo operando ingresado por el usuario.
 * \return la suma de los operandos.
 *
 */

float suma (float op1,float op2);

/** \brief recibe dos numeros y calcula la resta de ellos.
 *
 * \param op1 corresponde al primer operando ingresado por el usuario.
 * \param op2 corresponde al segundo operando ingresado por el usuario.
 * \return la resta de los operandos.
 *
 */

float resta (float op1,float op2);

/** \brief recibe dos numeros y los multiplica.
 *
 * \param op1 corresponde al primer operando ingresado por el usuario.
 * \param op2 corresponde al segundo operando ingresado por el usuario.
 * \return el producto de los operandos.
 *
 */

float multiplicacion (float op1,float op2);

/** \brief recibe dos numeros y calcula la division de ellos.
 *
 * \param op1 corresponde al primer operando ingresado por el usuario.
 * \param op2 corresponde al segundo operando ingresado por el usuario.
 * \return la division de los operandos.
 *
 */

double division (float op1,float op2);

/** \brief multiplica el operando ingresado, por sus numeros anteriores hasta llegar al numero uno.
 *
 * \param op1 corresponde al primer operando ingresado por el usuario.
 * \return el factorial del operando ingresado.
 *
 */

long double factorial(float op1);

#endif // FUNCIONES_H_INCLUDED
