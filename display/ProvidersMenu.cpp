//
// Created by digas on 29/12/2019.
//

#include "Menu.h"

void Menu::runProvidersMenu() {
    int option;

    while(true) {
        menuSeparator();

        cout << "Welcome to the Provider's menu! What do you want to do?" << endl << endl;
        cout << "Please choose what is your option:" << endl << endl;

        cout << "Go back                                                            [0]" << endl;
        cout << "Change specific provider reputation                                [1]" << endl;
        cout << "Adquire a product from provider                                    [2]" << endl;

        cout << "Insert the number correspondent to your option: ";
        cin >> option;
        validOption(option, 2);

        menuSeparator();

        if (option == 0) break;
        else if (option == 1) changeProviderOption();
        else if (option == 2) buyFromProviderOption();
    }
}

void Menu::changeProviderOption() {
    int option;
    vector<Providers> temp;
    int counter = 0;
    float new_value;
    string user_input;

    while (true) {
        menuSeparator();
        cout << "Please choose the provider you want to change reputation:" << endl << endl;

        cout << "Go back                                                            [0]" << endl;
        showAllProvidersName();

        cout << "Insert the number correspondent to your option: ";
        cin >> option;
        validOption(option, providers.size());

        menuSeparator();

        if (option == 0) break;

        while (!providers.empty()){
            counter ++;
            Providers p = providers.top();
            providers.pop();

            if (counter == option){
                cout << p.getName() << " current reputation: " << p.getReputation() << endl << endl;
                new_value = askForFloat(user_input, "Insert new value (0-100)", 0, 100);

                p.setReputation(new_value);
                providers.push(p);

                for (auto prov: temp) providers.push(prov);
                break;
            }
            else temp.push_back(p);
        }
        break;
    }
}

void Menu::buyFromProviderOption() {
    vector<string> temp;
    int option, opinion;
    vector<Providers> temp_providers;

    while (true){
        menuSeparator();

        temp = getAvailableEquipement();
        cout << "Please select the equipement that will be bought:" << endl << endl;

        cout << "Go back                                                            [0]" << endl;
        showAvailableEquipement(temp);

        cout << "Insert the number correspondent to your option: ";
        cin >> option;
        validOption(option, temp.size());

        menuSeparator();

        if (option == 0) break;

        cout << "The product: " << temp[option-1] << " has successfully been bought from ";
        cout << getProvider(temp[option-1]).getName() << "!" << endl;

        menuSeparator();

        cout << "Please leave an opinion about the purchase:" << endl << endl;

        cout << "Very good                                                          [4]" << endl;
        cout << "Good                                                               [3]" << endl;
        cout << "Bad                                                                [2]" << endl;
        cout << "Very bad                                                           [1]" << endl;
        cout << "No opinion                                                         [0]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> opinion;
        validOption(opinion, 4);

        if (opinion == 0) break;

        while (!providers.empty()){
            Providers p = providers.top();

            if (p.getName() == getProvider(temp[option-1]).getName()){
                if (opinion == 4){
                    if (p.getReputation() + 6 > 100) p.setReputation(100);
                    else p.setReputation(p.getReputation() + 6);
                }
                if (opinion == 3){
                    if (p.getReputation() + 2 > 100) p.setReputation(100);
                    else p.setReputation(p.getReputation() + 2);
                }
                if (opinion == 2){
                    if (p.getReputation() - 2 < 100) p.setReputation(0);
                    else p.setReputation(p.getReputation() - 2);
                }
                if (opinion == 1){
                    if (p.getReputation() - 6 > 100) p.setReputation(0);
                    else p.setReputation(p.getReputation() - 6);
                }

                providers.pop();
                providers.push(p);
                for (auto provider:temp_providers) providers.push(provider);
                break;
            }
            else temp_providers.push_back(p);
            providers.pop();
        }

    }
}