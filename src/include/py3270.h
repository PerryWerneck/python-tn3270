/*
 * "Software pw3270, desenvolvido com base nos códigos fontes do WC3270  e X3270
 * (Paul Mattes Paul.Mattes@usa.net), de emulação de terminal 3270 para acesso a
 * aplicativos mainframe. Registro no INPI sob o nome G3270.
 *
 * Copyright (C) <2008> <Banco do Brasil S.A.>
 *
 * Este programa é software livre. Você pode redistribuí-lo e/ou modificá-lo sob
 * os termos da GPL v.2 - Licença Pública Geral  GNU,  conforme  publicado  pela
 * Free Software Foundation.
 *
 * Este programa é distribuído na expectativa de  ser  útil,  mas  SEM  QUALQUER
 * GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou  de  ADEQUAÇÃO
 * A QUALQUER PROPÓSITO EM PARTICULAR. Consulte a Licença Pública Geral GNU para
 * obter mais detalhes.
 *
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este
 * programa; se não, escreva para a Free Software Foundation, Inc., 51 Franklin
 * St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Este programa está nomeado como - e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 */

#ifndef PY3270_H_INCLUDED

	#define PY3270_H_INCLUDED

	#define PY_SSIZE_T_CLEAN
	#include <Python.h>

	#include <config.h>

	#if defined(_WIN32)

			#include <windows.h>

			#define DLL_PRIVATE	extern
			#define DLL_PUBLIC	extern __declspec (dllexport)

	#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x550)

			#define DLL_PRIVATE		__hidden extern
			#define DLL_PUBLIC		extern

	#elif defined (HAVE_GNUC_VISIBILITY)

			#define DLL_PRIVATE		__attribute__((visibility("hidden"))) extern
			#define DLL_PUBLIC		__attribute__((visibility("default"))) extern

	#else

			#error Unable to set visibility attribute

	#endif

#ifdef __cplusplus

	#include <functional>
	#include <exception>
	#include <stdexcept>
	#include <lib3270/ipc.h>

	using std::exception;
	using std::runtime_error;
	using TN3270::Host;

	extern "C" {

#else

	typedef void Host;

#endif

		typedef struct {
			PyObject_HEAD
			Host *host;
		} pySession;

		DLL_PRIVATE PyObject * py3270_get_module_version(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject * py3270_get_module_revision(PyObject *self, PyObject *args);

		DLL_PRIVATE PyObject * py3270_session_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
//		DLL_PRIVATE int py3270_session_init(pySession *self, PyObject *args, PyObject *kwds);
		DLL_PRIVATE void py3270_session_dealloc(pySession * self);


		/*

		DLL_PRIVATE PyObject	* py3270_alloc(PyTypeObject *type, PyObject *args, PyObject *kwds);
		DLL_PRIVATE int			  py3270_init(py3270_TerminalObject *self, PyObject *args, PyObject *kwds);
		DLL_PRIVATE void		  py3270_dealloc(py3270_TerminalObject * self);

		DLL_PRIVATE PyObject	* terminal_get_version(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject	* terminal_get_revision(PyObject *self, PyObject *args);

		DLL_PRIVATE PyObject	* terminal_is_connected(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject	* terminal_is_ready(PyObject *self, PyObject *args);

		DLL_PRIVATE PyObject	* terminal_connect(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject	* terminal_disconnect(PyObject *self, PyObject *args);

		DLL_PRIVATE PyObject 	* terminal_get_string_at(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject 	* terminal_get_contents(PyObject *self);
		DLL_PRIVATE PyObject 	* terminal_set_string_at(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject	* terminal_cmp_string_at(PyObject *self, PyObject *args);

		DLL_PRIVATE PyObject 	* terminal_pfkey(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject 	* terminal_pakey(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject 	* terminal_enter(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject 	* terminal_action(PyObject *self, PyObject *args);

		DLL_PRIVATE PyObject 	* terminal_is_protected_at(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject 	* terminal_set_cursor_at(PyObject *self, PyObject *args);

		DLL_PRIVATE PyObject	* terminal_wait_for_ready(PyObject *self, PyObject *args);
		DLL_PRIVATE PyObject	* terminal_wait_for_string_at(PyObject *self, PyObject *args);
		*/

#ifdef __cplusplus
	}
#endif

#endif // PY3270_H_INCLUDED
