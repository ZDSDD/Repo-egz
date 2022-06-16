//
// Created by User on 13.06.2022.
//

#include "List.h"

using namespace std;

#include <iostream>

List::~List() {
    Node *Killer;
    while (pocz != nullptr) {
        Killer = pocz;
        pocz = pocz->nast;
        delete Killer;
    }
}

void List::insert(const string &IBAN, int IBAN_LEN) {

    /*Inserting with sort*/
    cout << "Dodaje " << IBAN << "\n_________\n";
    printList();
    cout << "\n_________\n";
    counter++;
    Node *New = new Node(IBAN);
    if (pocz == nullptr) {
        pocz = New;
    } else if (pocz != nullptr) {
        int j;
        Node *Pom;
        Node *Pom2;
        Node *Runner = pocz;
        Node *PreRunner;
        if (pocz->nast == nullptr) {
            for (j = 2; j < IBAN_LEN; j++) {
                if (pocz->iban[j] < IBAN[j]) {
                    pocz->nast = New;
                    return;
                } else if (pocz->iban[j] > IBAN[j]) {
                    New->nast = pocz;
                    pocz = New;
                    return;
                }
            }
        } else {
            for (j = 2; j < IBAN_LEN; j++) {
                Runner = pocz;
                while (Runner != nullptr) {
                    if (Runner->iban[j] > IBAN[j]) {
                        if (Runner == pocz) {
                            New->nast = pocz;
                            pocz = New;
                            return;
                        } else {
                            PreRunner->nast = New;
                            New->nast = Runner;
                            return;
                        }
                    } else if (Runner->iban[j] < IBAN[j]) {
                        if (Runner->nast == nullptr || Runner->nast->iban[j] > IBAN[j]) {
                            New->nast = Runner->nast;
                            Runner->nast = New;
                            return;
                        }
                    } else { /*If equal*/
                        Pom = Runner;
                        Pom2 = PreRunner;
                        if (Runner->nast == nullptr) {
                            for (int i = j; i < IBAN_LEN; i++) {
                                if (Runner->iban[i] > IBAN[i]) {
                                    if (Runner == pocz) {
                                        New->nast = pocz;
                                        pocz = New;
                                        return;
                                    } else {
                                        PreRunner->nast = New;
                                        New->nast = Runner;
                                        return;
                                    }
                                } else if (Runner->iban[i] < IBAN[i]) {

                                    New->nast = Runner->nast;
                                    Runner->nast = New;

                                    return;
                                }
                            }
                        }
                        for (int i = j; i < IBAN_LEN; i++) {
                            Runner = Pom;
                            PreRunner = Pom2;
                            while (Runner != nullptr && Runner->iban[j] == IBAN[j]) {

                                if (Runner->iban[i] > IBAN[i]) {
                                    if (Runner == pocz) {

                                        New->nast = pocz;
                                        pocz = New;
                                        return;
                                    } else {

                                        PreRunner->nast = New;
                                        New->nast = Runner;
                                        return;
                                    }
                                } else if (Runner->iban[i] < IBAN[i]) {
                                    if ((Runner->nast->iban[j] == IBAN[j] && Runner->nast->iban[i] >= IBAN[i])||Runner->nast->iban[j]!=IBAN[j]) {

                                        New->nast = Runner->nast;
                                        Runner->nast = New;
                                        return;
                                    }
                                }

                                PreRunner = Runner;
                                Runner = Runner->nast;
                            }
                        }
                    }
                    PreRunner = Runner;
                    Runner = Runner->nast;
                }
            }
            cout << "IBAN was already in: " << IBAN << endl;
        }
    }
}

void List::printList() {
    Node *Runner = pocz;
    while (Runner != nullptr) {
        cout << Runner->iban << endl;
        Runner = Runner->nast;
    }
}