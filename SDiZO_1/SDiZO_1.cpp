// SDiZO_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;



void Menu(Array *&arr, List *&list, Heap *&heap, RBTree *&tree) {

	char ch_1, ch_2;
	bool running = true, structure = false, testing = false;
	chrono::time_point<chrono::system_clock>start, end;
	int iter, test_count = 1;
	double _time;
	do {
		string choice1 = "abc", choice2 = "abc";

		cout << "\nWybierz strukture: \n1. Tablica \n2. Lista dwukierunkowa \n3. Kopiec \n4. Drzewo RB \n5. Generuj dane pseudolosowe \n6. Test mode ON/OFF \n7. Zakoncz\n";
		cin >> choice1;
		ch_1 = choice1.at(0);
		if (ch_1 == '7') return;

		if (ch_1 == '5') {
			int value, count;
			ofstream file;
			cout << "Podaj ilosc danych\n";
			cin >> count;
			file.open("Data.txt", std::ofstream::out | std::ofstream::trunc);
			file.close();
			file.open("Data.txt");

			file << count << endl;

			srand(time(NULL));
			for (int i = 0; i < count; ++i) {
				value = rand() % 2147483640;
				file << to_string(value) << endl;
			}
			file.close();
			cout << "Dane wygenerowane\n";
		}

		if (ch_1 == '6') {

			if (testing) {
				testing = false;
				cout << "Testing mode: OFF\n";
			}
			else {
				cout << "Wpisz ilosc powtorzen testu:\n";
				cin >> test_count;
				if (test_count > 0) {
					testing = true;
					cout << "Testing mode: ON\n";
				}
				else{
					cout << "Ilosc testow musi byc co najmniej 1!\n";
				}
			}
		}

		if (choice1.length() == 1 && ch_1 != '5' && ch_1 != '6') {
			do {
				cout << "\n1. Zbuduj z pliku \n2. Usun \n3. Dodaj \n4. Znajdz \n5. Wyswietl\n6. Cofnij\n";
				cin >> choice2;
				if (choice2.length() == 1) {
					ch_2 = choice2.at(0);
					structure = true;

					switch (ch_1) {

							//array operations
					case '1': {
						switch (ch_2) {
						case '1': {
							iter = 0;
							_time = 0;
							do {
								start = chrono::system_clock::now();

								ifstream file("Data.txt");
								string text;
								int num_count;
								delete arr;
								arr = new(nothrow)Array();

								getline(file, text);
								num_count = stoi(text);
								if (file.is_open()) {
									for (int i = 0; i < num_count; i++) {
										getline(file, text);
										arr->Add(i, stoi(text));
									}
								}
								file.close();
								cout << "Wartosci dodane\n";

								end = chrono::system_clock::now();
								chrono::duration<double> seconds = end - start;
								cout << "\ntime: " << seconds.count() << "s\n";
								_time += seconds.count();
								if (!testing) iter += test_count;
								iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '2': {
							int ind;
							iter = 0;
							_time = 0;
							do{
								cout << "Podaj indeks:\n";
								cin >> ind;
								start = chrono::system_clock::now();
								arr->Remove(ind);

								end = chrono::system_clock::now();
								chrono::duration<double> seconds = end - start;
								cout << "\nTime: " << seconds.count() << "s\n";
								_time += seconds.count();
								if (!testing) iter += test_count;
								iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '3': {
							int ind, value;
							iter = 0;
							_time = 0;
							do {
							cout << "Podaj indeks:\n";
							cin >> ind;
							cout << "Podaj wartosc:\n";
							cin >> value;
							start = chrono::system_clock::now();
							if (arr->Add(ind, value)) cout << "Wartosc dodana.\n";

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '4': {
							int value;
							bool search;
							iter = 0;
							_time = 0;
							do {
							cout << "Podaj wartosc:\n";
							cin >> value;
							start = chrono::system_clock::now();
							search = arr->Search(value);
							if (search) { cout << "Wartosc znaleziona\n"; }
							else { cout << "Wartosc nieznaleziona\n"; }

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '5': {
							iter = 0;
							_time = 0;
							do {
							start = chrono::system_clock::now();
							for (int i = 0; i < arr->GetSize(); i++) {
								cout << arr->GetValue(i) << "|";
							}

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '6': structure = false; break;
						default: {
							cout << "Nie ma takiej operacji!\n";
							structure = false;
						}
						}
						break;
					}

							  //list operations
					case '2': {
						switch (ch_2) {
						case '1': {
							iter = 0;
							_time = 0;
							do {
							start = chrono::system_clock::now();
							ifstream file("Data.txt");
							string text;
							int num_count;
							delete list;
							list = new(nothrow)List();

							getline(file, text);
							num_count = stoi(text);
							for (int i = 0; i < num_count; i++) {
								getline(file, text);
								list->AddFr(stoi(text));
							}
							file.close();

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '2': {
							int value;
							iter = 0;
							_time = 0;
							do {
							cout << "Podaj wartosc:\n";
							cin >> value;
							start = chrono::system_clock::now();
							list->Remove(value);

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '3': {
							int value1, value2;
							iter = 0;
							_time = 0;
							do{
							cout << "Podaj wartosc 1:\n";
							cin >> value1;
							cout << "Podaj wartosc 2:\n";
							cin >> value2;
							start = chrono::system_clock::now();
							list->Add(value1, value2);

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '4': {
							int value;
							bool search;
							iter = 0;
							_time = 0;
							do {
							cout << "Podaj wartosc:\n";
							cin >> value;
							start = chrono::system_clock::now();
							search = list->Search(value);
							if (search) { cout << "Wartosc znaleziona\n"; }
							else { cout << "Wartosc nieznaleziona\n"; }

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '5': {
							iter = 0;
							_time = 0;
							do {
							start = chrono::system_clock::now();
							list->Display();

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '6': structure = false; break;
						default: {
							cout << "Nie ma takiej operacji!\n";
							structure = false;
						}
						}
						break;
					}

							  //heap operations
					case '3': {
						switch (ch_2) {
						case '1': {
							iter = 0;
							_time = 0;
							do {
							start = chrono::system_clock::now();
							ifstream file("Data.txt");
							string text;
							int num_count;
							delete heap;
							heap = new(nothrow)Heap();

							getline(file, text);
							num_count = stoi(text);
							if (file.is_open()) {
								for (int i = 0; i < num_count; i++) {
									getline(file, text);
									int number = stoi(text);
									heap->Add(number);
								}
							}
							file.close();
							cout << "Wartosci dodane.\n";

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '2': {
							int value;
							iter = 0;
							_time = 0;
							do {
							cout << "Podaj wartosc:\n";
							cin >> value;
							start = chrono::system_clock::now();

							heap->Remove(value);

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '3': {
							int value;
							iter = 0;
							_time = 0;
							do {
							cout << "Podaj wartosc:\n";
							cin >> value;
							start = chrono::system_clock::now();
							if (heap->Add(value)) cout << "Wartosc dodana.\n";

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '4': {
							int value, search;
							iter = 0;
							_time = 0;
							do {
							cout << "Podaj wartosc:\n";
							cin >> value;
							start = chrono::system_clock::now();
							search = heap->Search(value);
							if (search == -1) { cout << "Nie znaleziono wartosci\n"; }
							else { cout << "Znaleziono wartosc\n"; }

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '5': {
							iter = 0;
							_time = 0;
							do {
							start = chrono::system_clock::now();
							heap->Display();

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '6': structure = false; break;
						default: {
							cout << "Nie ma takiej operacji!\n";
							structure = false;
						}
						}
						break;
					}
								//RB tree operations
					case '4': {
						switch (ch_2) {
						case '1': {
							iter = 0;
							_time = 0;
							do {
							start = chrono::system_clock::now();
							ifstream file("Data.txt");
							string text;
							int num_count;
							delete tree;
							tree = new(nothrow)RBTree();

							getline(file, text);
							num_count = stoi(text);
							if (file.is_open()) {
								for (int i = 0; i < num_count; i++) {
									getline(file, text);
									int number = stoi(text);
									tree->Add(number);
								}
							}
							file.close();
							cout << "Wartosci dodane.\n";

							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '2': {
							int k;
							bool removed;
							iter = 0;
							_time = 0;
							do {
							cout << "Wybierz klucz\n";
							cin >> k;
							start = chrono::system_clock::now();
							removed = tree->Remove(k);
							if (removed) cout << "Klucz usuniety\n";
							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '3': {
							int k;
							iter = 0;
							_time = 0;
							do {
							cout << "Wybierz klucz\n";
							cin >> k;
							start = chrono::system_clock::now();
							tree->Add(k);
							cout << "Klucz dodany\n";
							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '4': {
							int k;
							RBNode *node;
							iter = 0;
							_time = 0;
							do {
							cout << "Wybierz klucz\n";
							cin >> k;
							start = chrono::system_clock::now();
							node = tree->Search(k);
							if (node == NULL) cout << "Klucz znaleziony.\n";
							else cout << "Nie znaleziono klucza.\n";
							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '5': {
							iter = 0;
							_time = 0;
							do {
							start = chrono::system_clock::now();
							tree->Display();
							end = chrono::system_clock::now();
							chrono::duration<double> seconds = end - start;
							cout << "\nTime: " << seconds.count() << "s\n";
							_time += seconds.count();
							if (!testing) iter += test_count;
							iter++;
							} while (iter < test_count);
							if (testing) cout << "Sredni czas: " << _time / test_count << endl;
							break;
						}
						case '6': structure = false; break;
						default: {
							cout << "Nie ma takiej operacji!\n";
							structure = false;
						}
						}
						break;
					}
					case '7': {
						running = false;
						structure = false;
						break;
					}
					default: {
						cout << "Nie ma takiej opcji!\n";
						structure = false;
					}
					}
				}
			}while (structure);
		}
	}while (running);
}





int main()
{


	List *list;
	Heap *heap;
	string text;
	Array *arr;
	RBTree *tree;
	int  num_count;
		arr = new(nothrow)Array();			//allocating array
		heap = new(nothrow)Heap();			//allocating heap
		list = new(nothrow)List();			//allocating list
		tree = new(nothrow)RBTree();		//allocating RB tree
		Menu(*&arr, *&list, *&heap, *&tree);


	delete arr;								//deleting list, array, heap and RB tree
	delete list;
	delete heap;
	delete tree;
	cout << endl;
	system("pause");

    return 0;
}

