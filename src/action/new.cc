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
 * Este programa está nomeado como py3270.cc e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas Mendonça)
 *
 * Implementa métodos básicos inicio/final do objeto python
 *
 * Referências:
 *
 * <https://pythonextensionpatterns.readthedocs.io/en/latest/refcount.html>
 *
 *
 */

 #include <py3270.h>
 #include <lib3270/ipc.h>

/*---[ Implement ]----------------------------------------------------------------------------------*/

DLL_PRIVATE PyObject * py3270_action_new_from_session(PyObject *session, void *action) {

	pyAction * pObj = (pyAction *) _PyObject_New(&py3270_action_type);

	pObj->session = session;
	pObj->action = ((pySession *) session)->host->getAction((const LIB3270_ACTION *) action);

	debug("%s: ob_refcnt@%p=%ld",__FUNCTION__,pObj,((PyObject *) pObj)->ob_refcnt);

	Py_INCREF(pObj->session);

	return (PyObject *) pObj;

}

void py3270_action_dealloc(PyObject * self) {

	pyAction * pObj = (pyAction *) self;

	debug("%s: %p",__FUNCTION__,self);

	Py_DECREF(pObj->session);

	delete pObj->action;
	pObj->action = nullptr;

}

