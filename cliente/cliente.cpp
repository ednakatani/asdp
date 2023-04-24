//
// CLIENTE DE CONTA BANCÁRIA SIMPLES
//
// Arquitetura de Sistemas Distribuídos, Paralelos e Concorrentes
// Escola Politécnica -- PUCPR
// Prof. Luiz Lima Jr. (laplima@ppgia.pucpr.br)
//

#include <iostream>
#include <string>
#include "CEtcdC.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "USAGE: " << argv[0] << " file://<ior_file>" << endl;
		return 1;
	}

	try {
		// 1. Initiate ORB
		CORBA::ORB_var orb = CORBA::ORB_init(argc,argv,"ORB");

		// 2. Obtain object reference
		CORBA::Object_ptr tmp_ref;
		Etcd_var dictionary;

		tmp_ref = orb->string_to_object(argv[1]);
		dictionary = Etcd::_narrow(tmp_ref);

		// 3. Use dictionary

		string command;
		string dest_ior;
		string key;
		string val;

		cout << "Commandos:\n\tid\n\tput(key,val)\n\tget(key)\n\tdel(key)\n\tend" 
			<< endl;

		do {
			cout << "> ";
			cin >> command;
			
			if (command == "id") 
			{	
				cout << "\tId = " << dictionary->id() << endl;
				cout << "\tOK" << endl;	
			} 
			else if (command == "put") 
			{	
				cout << "Insert key: " ;
				cin >> key;
				
				cout << "Insert value: " ;
				cin >> val;
				
				cout << "\tput = " << dictionary->put(key, val) << endl;
				cout << "\tOK" << endl;	
			} 
			else if (command == "get") 
			{	
				cout << "Insert key: ";
				cin >> key;

				dictionary->get(key);
				
				cout << "\tOK" << endl;	
			} 
			else if (command == "del") 
			{	
				cout << "Insert key to delete: ";
				cin >> key;

				dictionary->del(key);
				
				cout << "\tOK" << endl;	
			} 

		} while (command != "end");

		// 4. Destroi ORB
		orb->destroy();

	} catch (CORBA::Exception& e) {
		cerr << "CORBA EXCEPTION:" << e << endl;
	}

	return 0;
}
