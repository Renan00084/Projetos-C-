/*Elabore um algoritmo que simule a escolhe do seu Pokémon inicial, a batalha contra o rival, 
tendo como opções lutar, capturar (apenas na segunda parte do código) ou correr, 
e depois simule o treinador indo para a próxima cidade passando por 10 gramas altas no total.
Considere os níveis de cada Pokémon e seus ataques.
Considere as regras de captura quando for selecionado capturar (as mesmas da outra questão lendária)
Considere que, caso o seu Pokémon morra, você volte para a cidade que começou, porem seu Pokémon não perde seu nível.
Considere que a chance de encontrar um Pokémon na grama alta, qual Pokémon vai ser achado e seu nível seja definido aleatoriamente.
Considere que, depois do treinador sair da primeira cidade, ele ganhara 5 Pokebolas  para capturar os Pokémon. 
= Dano doa atkqs = (((((2 * Nível do atacante / 5) + 2) * Potência do movimento * Ataque do atacante) / Defesa do defensor) / 50) + 2
c = nv7 = ember poder = 40/  hp = 20 +2hp por nivel/ atk = 11 def = 10/ atk e def+2 por nivel/
s = nv = 7 bublle poder = 20/ nv13 = water gun / hp = 20 + 2por nivel/ atk = 11  def = 13 / atk e def + 2por nivel/
b = nv7 = Leech seed (- 5% vidaAdv)/ hp = 21 + 2por nivel / atk = 11 def = 11/ atk e def + 2 por nivel/
nivel max = 15 / c= niv 13 = metal claw/ poder = 50/ growl = (-10% da atkAdv)
s = nv 13 = water gun / poder = 40 / tail whip = (-10% da defAdv)
b nv 13 = vine whip / poder = 35 / growl = (-10% da atkAdv)

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int escolha, nivel, nivelAdv, atk, atkAdv, def, defAdv, critico, decidirAdv, acaba = 0, contGM, acharP, pokemonEnco, b7 = 0, b13 = 0, s7 = 0, s13 = 0, c7 = 0, c13 = 0, contNivel = 0, taxaBase, pokebolas = 5, vidaMax, chanceCaptura, queimar, queimando = 0, fugir, lS = 0;
    
    char pokemon, pokemonAdv, tipo, tipoAdv;
    
    float vida, vidaAdv, dano, vidaAux, vidaAdvAux; 
    
    unsigned seed = time(0);
    
    srand(seed);
    
    critico = 1+ rand() % 100;
    
    do{
        cout << "\nEscolha o seu Pokemon Inicial:\n1 - Squirtle\n2 - Charmander\n3 - Bulbassaur\n";
        cin >> escolha;
        
        if((escolha != 1) && (escolha != 2) && (escolha != 3)){
            cout << "\nO valor digitado nao eh equivalente a nenhum Pokemon\nPor favor, tente novamente\n";
        }
    }while ((escolha != 1) && (escolha != 2) && (escolha != 3));
    
    switch (escolha){
        case 1: 
            cout << "\nParabens!! Voce escolheu um Squirtle!\n";
            cout << "\nJa o seu rival escolheu o Bulbasaur\n";
            pokemon = 's';
            pokemonAdv = 'b';
            tipo = 'a';
            tipo = 'g';
            nivel = 5;
            nivelAdv = 5;
            vida = 20;
            vidaAux = vida;
            vidaAdv = 21;
            vidaAdvAux = vidaAdv;
            atk = 11;
            atkAdv = 11;
            def = 13;
            defAdv = 11;
        break;
        
        case 2: 
            cout << "\nParabens!! Voce escolheu um Charmander!\n";
            cout << "\nJa o seu rival escolheu o Squirtle\n";
            pokemon = 'c';
            pokemonAdv = 's';
            tipo = 'f';
            tipoAdv = 'a';
            nivel = 5;
            nivelAdv = 5;
            vida = 20;
            vidaAux = vida;
            vidaAdv = 20;
            vidaAdvAux = vidaAdv;
            atk = 11;
            atkAdv = 11;
            def = 10;
            defAdv = 13;
        break;
        
        default: 
            cout << "\nParabens!! Voce escolheu um Bulbassaur!\n";
            cout << "\nJa o seu rival escolheu o Charmander\n";
            pokemon = 'b';
            pokemonAdv = 'c';
            tipo = 'g';
            tipoAdv = 'f';
            nivel = 5;
            nivelAdv = 5;
            vida = 21;
            vidaAux = vida;
            vidaAdv = 20;
            vidaAdvAux = vidaAdv;
            atk = 11;
            atkAdv = 11;
            def = 11;
            defAdv = 10;
        break;
        
    }
    
    cout << "\nQuando voce estava prestes a sair da laboratorio do Professor Carvalho o seu rival Blue resolve te desafiar para uma batalha Pokemon!\n";
    cout << "\nQue a batalha comece!\n";
    
    while (((vida > 0) && (vidaAdv > 0)) && (acaba == 0)){
        cout << "\nDigite o que voce deseja fazer:\n1 - Lutar\n2 - Capturar\n3 - Fugir\n";
        cin >> escolha;
        
        if((pokemon == 's') && (escolha == 1)){
            cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n";
            cin >> escolha;
            
            switch (escolha){
                case 1:
                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                    critico = 1+ rand() % 100;
                    
                    if(critico > 90){
                        dano = dano * 1.5;
                        cout << "\nO ataque foi critico!\n";
                        
                    }
                    vidaAdv = vidaAdv - dano;
                    cout << "\nSeu Squirtle ataca Bulbasaur usando Tackle!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vidaAdv << "\n";
                break;
                
                case 2: 
                    defAdv = defAdv - ((defAdv * 10) / 100);
                    cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Bulbasaur e de " << defAdv << " \n";
                break;
            }
            if(vida <= 0){
                cout << "\nVoce perdeu a batalha\n";
                acaba = 1;
                vida = vidaAux;
                
            }else{
                if(vidaAdv <= 0){
                    cout << "\nVoce ganhou a batalha contra o seu rival!\nSeu Pokemon evoluiu 2 niveis!\n";
                    vida = vidaAux;
                    vida = vida + 4;
                    vidaAux = vida;
                    atk = atk + 4;
                    def = def + 4;
                    nivel += 2;
                    acaba = 1;
                    cout << "\nSeu Squirtle aprendeu o ataque 'Bubble'\n";
                    
                }else{
                    cout << "\nAgora e o turno do seu Adversario!\n";
                    
                    decidirAdv = 1+ rand() % 2;
                    switch (decidirAdv){
                        case 1:
                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                            critico = 1+ rand() % 100;
                            
                            if(critico > 90){
                                dano = dano * 1.5;
                                cout << "\nO ataque de seu oponente foi critico!\n";
                                
                            }
                            vida = vida - dano;
                            cout << "\nO Bulbasaur do seu inimigo ataca seu Squirtle usando Tackle!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                        break;
                        
                        case 2:
                            atk = atk - ((atk * 10) / 100);
                            cout << "\nO Bulbasaur do seu inimigo usou Growl\nAgora o ataque de seu Squirtle e de " << atk << " \n";
                            
                        break;
                        
                    }
                    if(vida <= 0){
                        cout << "\nVoce perdeu a batalha\n";
                        vida = vidaAux;
                        acaba = 1;
                       
                    }else{
                        if(vidaAdv <= 0){
                            cout << "\nVoce ganhou a batalha contra o seu rival!\nSeu Pokemon evoluiu 2 niveis!\n";
                            vida = vidaAux;
                            vida = vida + 4;
                            vidaAux = vida;
                            atk = atk + 4;
                            def = def + 4;
                            nivel += 2;
                            acaba = 1;
                            cout << "\nSeu Squirtle aprendeu o ataque 'Bubble'\n";
                            
                        }
                    }
                }
            }
            
        }else{
            if((pokemon == 'c') && (escolha == 1)){
                cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n";
                cin >> escolha;
                
                switch (escolha){
                    case 1:
                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                        
                        critico = 1+ rand() % 100;
                        
                        if(critico > 90){
                            dano = dano * 1.5;
                            cout << "\nO ataque foi critico!\n";
                            
                        }
                        vidaAdv = vidaAdv - dano;
                        cout << "\nSeu Charmander ataca Squirtle usando Scratch!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vidaAdv << "\n";
                    break;
                    
                    case 2:
                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                        cout << "\nSeu Charmander usou Growl!\nAgora o ataque do Squirtle e de " << atkAdv << " \n";
                    break;
                }
                
                if(vida <= 0){
                    cout << "\nVoce perdeu a batalha\n";
                    acaba == 1;
                    vida = vidaAux;
                    
                }else{
                    if(vidaAdv <= 0){
                        cout << "\nVoce ganhou a batalha contra o seu rival!\nSeu Pokemon evoluiu 2 niveis!\n";
                        vida = vidaAux;
                        vida = vida + 4;
                        vidaAux = vida;
                        atk = atk + 4;
                        def = def + 4;
                        nivel += 2;
                        acaba = 1;
                        cout << "\nSeu Charmander aprendeu o ataque 'Ember'\n";
                        
                    }else{
                        cout << "\nAgora e o turno do seu Adversario!\n";
                        
                        decidirAdv = 1+ rand() % 2;
                        switch (decidirAdv){
                            case 1:
                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                critico = 1+ rand() % 100;
                                
                                if(critico > 90){
                                    dano = dano * 1.5;
                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                    
                                }
                                vida = vida - dano;
                                cout << "\nO Squirtle do seu inimigo ataca seu Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                            break;
                           
                            case 2:
                                def = def - ((def * 10) / 100);
                                cout << "\nO Squirtle do seu inimigo usou Tail Whip\nAgora a defesa de seu Charmander e de " << def << " \n";
                                
                            break;
                        }
                        if(vida <= 0){
                            cout << "\nVoce perdeu a batalha\n";
                            acaba = 1;
                            vida = vidaAux;
                            
                        }else{
                            if(vidaAdv <= 0){
                                cout << "\nVoce ganhou a batalha contra o seu rival!\nSeu Pokemon evoluiu 2 niveis!\n";
                                vida = vidaAux;
                                vida = vida + 4;
                                vidaAux = vida;
                                atk = atk + 4;
                                def = def + 4;
                                nivel += 2;
                                acaba = 1;
                                cout << "\nSeu Charmander aprendeu o ataque 'Ember'\n";
                                
                            }
                        }
                    }
                }
            }else{
                if((pokemon == 'b') && (escolha == 1)){
                    cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n";
                    cin >> escolha;
                    
                    switch (escolha){
                        case 1:
                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                            
                            critico = 1+ rand() % 100;
                            
                            if(critico > 90){
                                dano = dano * 1.5;
                                cout << "\nO ataque foi critico!\n";
                                
                            }
                            vidaAdv = vidaAdv - dano;
                            cout << "\nSeu Bulbasaur ataca Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vidaAdv << "\n";
                        break;
                        
                        case 2:
                            atkAdv = atkAdv - ((atkAdv * 10) / 100);
                            cout << "\nSeu Bulbasaur usou Growl!\nAgora o ataque do Charmander e de " << atkAdv << " \n";
                        break;
                    }
                    if(vida <= 0){
                        cout << "\nVoce perdeu a batalha\n";
                        acaba == 1;
                        vida = vidaAux;
                        
                    }else{
                        if(vidaAdv <= 0){
                            cout << "\nVoce ganhou a batalha contra o seu rival!\nSeu Pokemon evoluiu 2 niveis!\n";
                            vida = vidaAux;
                            vida = vida + 4;
                            vidaAux = vida;
                            atk = atk + 4;
                            def = def + 4;
                            nivel += 2;
                            acaba = 1;
                            cout << "\nSeu Bulbasaur aprendeu o ataque 'Leech seed'\n";
                            
                        }else{
                            cout << "\nAgora e o turno do seu Adversario!\n";
                            
                            decidirAdv = 1+ rand() % 2;
                            switch (decidirAdv){
                                case 1:
                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                        
                                    }
                                    vida = vida - dano;
                                    cout << "\nO Charmander do seu inimigo ataca seu Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                break;
                               
                                case 2:
                                    def = def - ((def * 10) / 100);
                                    cout << "\nO Charmander do seu inimigo usou Growl\nAgora o ataque de seu Bulbasaur e de " << atk << " \n";
                                    
                                break;
                            }
                            if(vida <= 0){
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                
                            }else{
                                if(vidaAdv <= 0){
                                    cout << "\nVoce ganhou a batalha contra o seu rival!\nSeu Pokemon evoluiu 2 niveis!\n";
                                    vida = vidaAux;
                                    vida = vida + 4;
                                    vidaAux = vida;
                                    atk = atk + 4;
                                    def = def + 4;
                                    nivel += 2;
                                    acaba = 1;
                                    cout << "\nSeu Bulbasaur aprendeu o ataque 'Leech seed'\n";
                                    
                                }
                            }
                        }
                    }
                }else{
                    if(escolha == 2){
                        cout << "\nVoce nao pode capturar o Pokemon de um outro treinador\n";
                    
                    }else{
                        if(escolha == 3){
                            cout << "\nVoce nao quer fugir, afinal, quer derrotar o seu maior rival!\n";
                            
                        }else{
                            cout << "\nO numero digitado nao indica nenhuma acao. Por favor tente novamente\n";
                        }
                    }
                }
            }
        }
    }
    cout << "\nApos curar seu Pokemon da batalha contra o seu rival, voce decide ir para a proxima cidade, tendo que passar por 10 gramas altas no caminho\n";
    nivelAdv = 0;
    
    for(contGM = 1; contGM <= 10; contGM++){
        lS = 0;
        queimando = 0;
        cout << "\n(Grama alta " << contGM << ")\n";
        cout << "\nVoce estava andando sobre a grama alta ate que...\n";
        acharP = 1+ rand() % 2;
        if(acharP == 1){
            pokemonEnco = 1+ rand() % 5;
            nivelAdv = 0;
            nivelAdv = 5+ rand() % 10;
            switch (pokemonEnco){
                case 1: //rattata
                    taxaBase = 255;
                    switch (nivelAdv){
                        case 5:
                            vidaAdv = 19;
                            atkAdv = 12;
                            defAdv = 10;
                            tipoAdv = 'n';
                        break;
                        
                        case 6:
                            vidaAdv = 21;
                            atkAdv = 14;
                            defAdv = 12;
                            tipoAdv = 'n';
                        break;
                        
                        case 7:
                            vidaAdv = 23;
                            atkAdv = 16;
                            defAdv = 14;
                            tipoAdv = 'n';
                        break;
                        
                        case 8:
                            vidaAdv = 25;
                            atkAdv = 18;
                            defAdv = 16;
                            tipoAdv = 'n';
                        break;
                        
                        case 9:
                            vidaAdv = 27;
                            atkAdv = 20;
                            defAdv = 18;
                            tipoAdv = 'n';
                        break;
                        
                        case 10:
                            vidaAdv = 29;
                            atkAdv = 22;
                            defAdv = 20;
                            tipoAdv = 'n';
                        break;
                    }
                break;
                
                case 2: //pidgey
                    taxaBase = 255;
                    switch (nivelAdv){
                        case 5:
                            vidaAdv = 20;
                            atkAdv = 11;
                            defAdv = 10;
                            tipoAdv = 'v';
                        break;
                        
                        case 6:
                            vidaAdv = 22;
                            atkAdv = 13;
                            defAdv = 12;
                            tipoAdv = 'v';
                        break;
                        
                        case 7:
                            vidaAdv = 24;
                            atkAdv = 15;
                            defAdv = 14;
                            tipoAdv = 'v';
                        break;
                        
                        case 8:
                            vidaAdv = 26;
                            atkAdv = 17;
                            defAdv = 16;
                            tipoAdv = 'v';
                        break;
                        
                        case 9:
                            vidaAdv = 28;
                            atkAdv = 19;
                            defAdv = 18;
                            tipoAdv = 'v';
                        break;
                        
                        case 10:
                            vidaAdv = 30;
                            atkAdv = 21;
                            defAdv = 20;
                            tipoAdv = 'v';
                        break;
                    }
                break;
                
                case 3: // Growlithe
                    taxaBase = 126;
                    switch (nivelAdv){
                        case 5:
                            vidaAdv = 22;
                            atkAdv = 13;
                            defAdv = 11;
                            tipoAdv = 'f';
                        break;
                        
                        case 6:
                            vidaAdv = 24;
                            atkAdv = 15;
                            defAdv = 13;
                            tipoAdv = 'f';
                        break;
                        
                        case 7:
                            vidaAdv = 26;
                            atkAdv = 17;
                            defAdv = 15;
                            tipoAdv = 'f';
                        break;
                        
                        case 8:
                            vidaAdv = 28;
                            atkAdv = 19;
                            defAdv = 17;
                            tipoAdv = 'f';
                        break;
                        
                        case 9:
                            vidaAdv = 30;
                            atkAdv = 21;
                            defAdv = 19;
                            tipoAdv = 'f';
                        break;
                        
                        case 10:
                            vidaAdv = 32;
                            atkAdv = 23;
                            defAdv = 21;
                            tipoAdv = 'f';
                        break;
                    }
                break;
                
                case 4: // Abra
                    taxaBase = 64;
                    switch (nivelAdv){
                        case 5:
                            vidaAdv = 19;
                            atkAdv = 8;
                            defAdv = 8;
                            tipoAdv = 'p';
                        break;
                        
                        case 6:
                            vidaAdv = 21;
                            atkAdv = 10;
                            defAdv = 10;
                            tipoAdv = 'p';
                        break;
                        
                        case 7:
                            vidaAdv = 23;
                            atkAdv = 12;
                            defAdv = 12;
                            tipoAdv = 'p';
                        break;
                        
                        case 8:
                            vidaAdv = 25;
                            atkAdv = 14;
                            defAdv = 14;
                            tipoAdv = 'p';
                        break;
                        
                        case 9:
                            vidaAdv = 27;
                            atkAdv = 16;
                            defAdv = 16;
                            tipoAdv = 'p';
                        break;
                        
                        case 10:
                            vidaAdv = 29;
                            atkAdv = 18;
                            defAdv = 18;
                            tipoAdv = 'p';
                        break;
                    }
                break;
                
                case 5: // Pikachu
                    taxaBase = 126;
                    switch (nivelAdv){
                        case 5:
                            vidaAdv = 20;
                            atkAdv = 12;
                            defAdv = 10;
                            tipoAdv = 'e';
                        break;
                        
                        case 6:
                            vidaAdv = 22;
                            atkAdv = 14;
                            defAdv = 12;
                            tipoAdv = 'e';
                        break;
                        
                        case 7:
                            vidaAdv = 24;
                            atkAdv = 16;
                            defAdv = 14;
                            tipoAdv = 'e';
                        break;
                        
                        case 8:
                            vidaAdv = 26;
                            atkAdv = 18;
                            defAdv = 16;
                            tipoAdv = 'e';
                        break;
                        
                        case 9:
                            vidaAdv = 28;
                            atkAdv = 20;
                            defAdv = 18;
                            tipoAdv = 'e';
                        break;
                        
                        case 10:
                            vidaAdv = 30;
                            atkAdv = 22;
                            defAdv = 20;
                            tipoAdv = 'e';
                        break;
                    }
                break;
                
                
            }
            acaba = 0;
            
            vidaMax = vida;
            
            switch(pokemonEnco){
                case 1: cout << "\nUm Rattata selvagem de nivel " << nivelAdv << " apareceu!\n"; break;
                case 2: cout << "\nUm Pidgey selvagem de nivel " << nivelAdv << " apareceu!\n"; break;
                case 3: cout << "\nUm Growlithe selvagem de nivel " << nivelAdv << " apareceu!\n"; break;
                case 4: cout << "\nUm Abra selvagem de nivel " << nivelAdv << " apareceu!\n"; break;
                case 5: cout << "\nUm Pikachu selvagem de nivel " << nivelAdv << " apareceu!\n"; break;
                
            }
            
            while (((vida > 0) && (vidaAdv > 0)) && (acaba == 0)){
                cout << "\nDigite o que voce deseja fazer:\n1 - Lutar\n2 - Capturar\n3 - Fugir\n";
                cin >> escolha;
                
                if((pokemon == 's') && (escolha == 1) && (pokemonEnco == 1)){
                    if(nivel >= 7){
                        s7 = 1;
                        
                    }else{
                        if(nivel >= 13){
                            cout << "\nO seu Squirtle aprendeu Water Gun!\n";
                            s13 = 1;
                            
                        }
                    }
                    
                    if((s7 == 0) && (s13 == 0)){
                        cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n";
                        cin >> escolha;
                        
                        switch (escolha){
                            case 1:
                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                critico = 1+ rand() % 100;
                                
                                if(critico > 90){
                                    dano = dano * 1.5;
                                    cout << "\nO ataque foi critico!\n";
                                    
                                }
                                vidaAdv = vidaAdv - dano;
                                cout << "\nSeu Squirtle ataca Rattata usando Tackle!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                            break;
                            
                            case 2: 
                                defAdv = defAdv - ((defAdv * 10) / 100);
                                cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Rattata e de " << defAdv << " \n";
                            break;
                        }
                        if(vida <= 0){
                            cout << "\nVoce perdeu a batalha\n";
                            acaba = 1;
                            vida = vidaAux;
                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                            contGM = 0;
                            
                        }else{
                            if(vidaAdv <= 0){
                                cout << "\nVoce ganhou a batalha!!\n";
                                contNivel++;
                                if((contNivel % 2) == 0){
                                    nivel++;
                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                    vidaAux += 2;
                                    vida += 2;
                                    atk += 2;
                                    def += 2;
                                    
                                }
                                acaba = 1;
                                
                            }else{
                                cout << "\nAgora eh o turno do seu oponente!\n";
                                
                                decidirAdv = 1+ rand() % 2;
                                switch (decidirAdv){
                                    case 1:
                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                            
                                        }
                                        vida = vida - dano;
                                        cout << "\nO Rattata selvagem ataca seu Squirtle usando Tackle!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                    break;
                                   
                                    case 2:
                                        def = def - ((def * 10) / 100);
                                        cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Squirtle e de " << def << " \n";
                                        
                                    break;
                                    
                                    
                                }
                                if(vida <= 0){
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                    }
                                }
                            }
                        }
                    }else{
                        if((s7 == 1) && (s13 == 0)){
                            cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n";
                            cin >> escolha;
                            
                            switch (escolha){
                                case 1:
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Squirtle ataca Rattata usando Tackle!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                break;
                                
                                case 2: 
                                    defAdv = defAdv - ((defAdv * 10) / 100);
                                    cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Rattata e de " << defAdv << " \n";
                                break;
                                
                                case 3:
                                    escolha = 0;
                                    dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Squirtle ataca Rattata usando Bubble!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                break;
                            }
                            if(vida <= 0){
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                                
                            }else{
                                if(vidaAdv <= 0){
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                        
                                    }
                                    acaba = 1;
                                    
                                }else{
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Rattata selvagem ataca seu Squirtle usando Tackle!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                        break;
                                       
                                        case 2:
                                            def = def - ((def * 10) / 100);
                                            cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Squirtle e de " << def << " \n";
                                            
                                        break;
                                        
                                     
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }
                            }  
                        }else{
                            if((s7 == 1) && (s13 == 1)){
                                cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n4 - Water Gun\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Rattata usando Tackle!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        defAdv = defAdv - ((defAdv * 10) / 100);
                                        cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Rattata e de " << defAdv << " \n";
                                    break;
                                    
                                    case 3:
                                        escolha = 0;
                                        dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Rattata usando Bubble!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 4:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Rattata usando Water Gun!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                }
                                if(vida <= 0){
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Rattata selvagem ataca seu Squirtle usando Tackle!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                            break;
                                           
                                            case 2:
                                                def = def - ((def * 10) / 100);
                                                cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Squirtle e de " << def << " \n";
                                                
                                            break;
                                            
                                         
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }else{
                    if((pokemon == 's') && (escolha == 1) && (pokemonEnco == 2)){
                        if(nivel >= 7){
                            s7 = 1;
                            
                        }else{
                            if(nivel >= 13){
                                cout << "\nO seu Squirtle aprendeu Water Gun!\n";
                                s13 = 1;
                                
                            }
                        }
                        
                        if((s7 == 0) && (s13 == 0)){
                            cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n";
                            cin >> escolha;
                            
                            switch (escolha){
                                case 1:
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Squirtle ataca Pidgey usando Tackle!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                break;
                                
                                case 2: 
                                    defAdv = defAdv - ((defAdv * 10) / 100);
                                    cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Pidgey e de " << defAdv << " \n";
                                break;
                            }
                            if(vida <= 0){
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                             
                            }else{
                                if(vidaAdv <= 0){
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                        
                                    }
                                    acaba = 1;
                                    
                                }else{
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Pidgey selvagem ataca seu Squirtle usando Tackle!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                        break;
                                       
                                        case 2:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                            
                                        break;
                                        
                                        
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }
                            }
                        }else{
                            if((s7 == 1) && (s13 == 0)){
                                cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Pidgey usando Tackle!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        defAdv = defAdv - ((defAdv * 10) / 100);
                                        cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Pidgey e de " << defAdv << " \n";
                                    break;
                                    
                                    case 3:
                                        escolha = 0;
                                        dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Pidgey usando Bubble!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                    break;
                                }
                                if(vida <= 0){
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Pidgey selvagem ataca seu Squirtle usando Tackle!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                    
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                                
                                            break;
                                            
                                         
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }  
                            }else{
                                if((s7 == 1) && (s13 == 1)){
                                    cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n4 - Water Gun\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Pidgey usando Tackle!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            defAdv = defAdv - ((defAdv * 10) / 100);
                                            cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Pidgey e de " << defAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Pidgey usando Bubble!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 4:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Pidgey usando Water Gun!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                            
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1+ rand() % 2;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pidgey selvagem ataca seu Squirtle usando Tackle!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                                    
                                                break;
                                             
                                             
                                            }
                                            if(vida <= 0){
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }else{
                        if((pokemon == 's') && (escolha == 1) && (pokemonEnco == 3)){
                            if(nivel >= 7){
                            s7 = 1;
                            
                        }else{
                            if(nivel >= 13){
                                cout << "\nO seu Squirtle aprendeu Water Gun!\n";
                                s13 = 1;
                                
                            }
                        }
                        
                        if((s7 == 0) && (s13 == 0)){
                            cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n";
                            cin >> escolha;
                            
                            switch (escolha){
                                case 1:
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Squirtle ataca Growlithe usando Tackle!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                break;
                                
                                case 2: 
                                defAdv = defAdv - ((defAdv * 10) / 100);
                                cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Growlithe e de " << defAdv << " \n";
                                break;
                            }
                            if(vida <= 0){
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                                
                            }else{
                                if(vidaAdv <= 0){
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                     
                                    }
                                    acaba = 1;
                                    
                                }else{
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                         
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Growlithe selvagem ataca seu Squirtle usando Bite!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                        break;
                                        
                                        case 2:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                         
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            dano *= 0.5;
                                            cout << "\nO ataque nao eh efetivo contra agua\n";
                                            vida = vida - dano;
                                            cout << "\nO Growlithe selvagem ataca seu Squirtle usando Ember!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                        break;
                                        
                                        
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }
                            }
                        }else{
                            if((s7 == 1) && (s13 == 0)){
                                cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                            if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Growlithe usando Tackle!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        defAdv = defAdv - ((defAdv * 10) / 100);
                                        cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Growlithe e de " << defAdv << " \n";
                                    break;
                                    
                                    case 3:
                                        escolha = 0;
                                        dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        dano *= 2;
                                        cout << "\nO ataque foi super efetivo\n";
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Growlithe usando Bubble!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                    break;
                                }
                                if(vida <= 0){
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                     
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                             
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Growlithe selvagem ataca seu Squirtle usando Bite!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                dano *= 0.5;
                                                cout << "\nO ataque nao eh efetivo contra agua\n";
                                                vida = vida - dano;
                                                cout << "\nO Growlithe selvagem ataca seu Squirtle usando Ember!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                                
                                            break;
                                            
                                         
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }  
                            }else{
                                if((s7 == 1) && (s13 == 1)){
                                    cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n4 - Water Gun\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Growlithe usando Tackle!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            defAdv = defAdv - ((defAdv * 10) / 100);
                                            cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Growlithe e de " << defAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            dano *= 2;
                                            cout << "\nO ataque eh super efetivo\n";
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Growlithe usando Bubble!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 4:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico\n";
                                            
                                            }
                                            dano *= 2;
                                            cout << "\nO ataque eh super efetivo\n";
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Growlithe usando Water Gun!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                            
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1+ rand() % 2;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Growlithe selvagem ataca seu Squirtle usando Bite!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    cout << "\nO ataque eh fraco contra agua\n";
                                                    dano = dano * 0.5;
                                                    vida = vida - dano;
                                                    cout << "\nO Growlithe selvagem ataca seu Squirtle usando Ember!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                                    
                                                break;
                                                
                                             
                                            }
                                            if(vida <= 0){
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    nivel++;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                }else{
                    if((pokemon == 's') && (escolha == 1) && (pokemonEnco == 4)){
                        if(nivel == 7){
                            s7 = 1;
                            
                        }else{
                            if(nivel == 13){
                                s13 = 1;
                                
                            }
                        }
                        
                        if((s7 == 0) && (s13 == 0)){
                            cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n";
                            cin >> escolha;
                            
                            switch (escolha){
                                case 1:
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Squirtle ataca Abra usando Tackle!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                break;
                                
                                case 2: 
                                defAdv = defAdv - ((defAdv * 10) / 100);
                                cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Abra e de " << defAdv << " \n";
                                break;
                            }
                            if(vida <= 0){
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                                
                            }else{
                                if(vidaAdv <= 0){
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        nivel++;
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                     
                                    }
                                    acaba = 1;
                                    
                                }else{
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1;
                                    switch (decidirAdv){
                                        case 1:
                                        cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                        vidaAdv = 0;
                                        break;
                                        
                                        
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }
                            }
                        }else{
                            if((s7 == 1) && (s13 == 0)){
                                cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                            if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Abra usando Tackle!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        defAdv = defAdv - ((defAdv * 10) / 100);
                                        cout << "\nSeu Squirtle usou Tail Whip\nAgora a Abra do Growlithe e de " << defAdv << " \n";
                                    break;
                                    
                                    case 3:
                                        escolha = 0;
                                        dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Abra usando Bubble!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                    break;
                                }
                                if(vida <= 0){
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                     
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1;
                                        switch (decidirAdv){
                                            case 1:
                                            cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                            vidaAdv = 0;
                                            break;
                                            
                                         
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }  
                            }else{
                                if((s7 == 1) && (s13 == 1)){
                                    cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n4 - Water Gun\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Abra usando Tackle!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            defAdv = defAdv - ((defAdv * 10) / 100);
                                            cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Abra e de " << defAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Abra usando Bubble!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 4:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico\n";
                                            
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Abra usando Water Gun!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                nivel++;
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                            
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1;
                                            switch (decidirAdv){
                                                case 1:
                                                cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                                vidaAdv = 0;
                                                break;
                                                
                                             
                                            }
                                            if(vida <= 0){
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }else{
                        if((pokemon == 's') && (escolha == 1) && (pokemonEnco == 5)){
                            if(nivel == 7){
                                s7 = 1;
                                
                            }else{
                                if(nivel == 13){
                                    s13 = 1;
                                    
                                }
                            }
                            
                            if((s7 == 0) && (s13 == 0)){
                                cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Squirtle ataca Pikachu usando Tackle!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                    defAdv = defAdv - ((defAdv * 10) / 100);
                                    cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Pikachu e de " << defAdv << " \n";
                                    break;
                                }
                                if(vida <= 0){
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                         
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                dano = dano * 2; // efetivo
                                                cout << "\nO ataque eh super efetivo!\n";
                                                vida = vida - dano;
                                                cout << "\nO Pikachu selvagem ataca seu Squirtle usando Thundershock!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                atk = atk - ((atk * 10) / 100);
                                                cout << "\nO Pikachu usou Growl!\nAgora o ataque do Squirtle e de " << atk << " \n";
                                            break;
                                            
                                            case 3:
                                                def = def - ((def * 10) / 100);
                                                cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Squirtle e de " << def << " \n";
                                            break;
                                            
                                            
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }
                            }else{
                                if((s7 == 1) && (s13 == 0)){
                                    cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                                if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Pikachu usando Tackle!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            defAdv = defAdv - ((defAdv * 10) / 100);
                                            cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Pikachu e de " << defAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            dano = dano * 2; // efetivo
                                            cout << "\nO ataque eh super efetivo!\n";
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Squirtle ataca Piakchu usando Bubble!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                        break;
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                         
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1;
                                            switch (decidirAdv){
                                                case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                dano = dano * 2; // efetivo
                                                cout << "\nO ataque eh super efetivo!\n";
                                                vida = vida - dano;
                                                cout << "\nO Pikachu selvagem ataca seu Squirtle usando Thundershock!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                atk = atk - ((atk * 10) / 100);
                                                cout << "\nO Pikachu usou Growl!\nAgora o ataque do Squirtle e de " << atk << " \n";
                                            break;
                                            
                                            case 3:
                                                def = def - ((def * 10) / 100);
                                                cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Squirtle e de " << def << " \n";
                                            break;
                                                
                                             
                                            }
                                            if(vida <= 0){
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }  
                                }else{
                                    if((s7 == 1) && (s13 == 1)){
                                        cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Tackle\n2 - Tail Whip\n3 - Bubble\n4 - Water Gun\n";
                                        cin >> escolha;
                                        
                                        switch (escolha){
                                            case 1:
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Squirtle ataca Pikachu usando Tackle!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 2: 
                                                defAdv = defAdv - ((defAdv * 10) / 100);
                                                cout << "\nSeu Squirtle usou Tail Whip\nAgora a defesa do Pikachu e de " << defAdv << " \n";
                                            break;
                                            
                                            case 3:
                                                escolha = 0;
                                                dano = (((((2 * nivel / 5) + 2) * 20 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                dano = dano * 2; // efetivo
                                                cout << "\nO ataque eh super efetivo!\n";
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Squirtle ataca Pikachu usando Bubble!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 4:
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico\n";
                                                    
                                                }
                                                dano = dano * 2; // efetivo
                                                cout << "\nO ataque é super efetivo!\n";
                                                vidaAdv = vidaAdv - dano;;
                                                cout << "\nSeu Squirtle ataca Pikachu usando Water Gun!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                                
                                            }else{
                                                cout << "\nAgora eh o turno do seu oponente!\n";
                                                
                                                decidirAdv = 1;
                                                switch (decidirAdv){
                                                    case 1:
                                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                        critico = 1+ rand() % 100;
                                                        
                                                        if(critico > 90){
                                                            dano = dano * 1.5;
                                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                                            
                                                        }
                                                        dano = dano * 2; // efetivo
                                                        cout << "\nO ataque eh super efetivo!\n";
                                                        vida = vida - dano;
                                                        cout << "\nO Pikachu selvagem ataca seu Squirtle usando Thundershock!\nO ataque causou " << dano << " de dano\nSquirtle agora esta com " << vida << "\n";
                                                    break;
                                                    
                                                    case 2:
                                                        atk = atk - ((atk * 10) / 100);
                                                        cout << "\nO Pikachu usou Growl!\nAgora o ataque do Squirtle e de " << atk << " \n";
                                                    break;
                                                    
                                                    case 3:
                                                        def = def - ((def * 10) / 100);
                                                        cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Squirtle e de " << def << " \n";
                                                    break;
                                                    
                                                 
                                                }
                                                if(vida <= 0){
                                                    cout << "\nVoce perdeu a batalha\n";
                                                    acaba = 1;
                                                    vida = vidaAux;
                                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                    contGM = 0;
                                                    
                                                }else{
                                                    if(vidaAdv <= 0){
                                                        cout << "\nVoce ganhou a batalha!!\n";
                                                        contNivel++;
                                                        if((contNivel % 2) == 0){
                                                            nivel++;
                                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                            vidaAux += 2;
                                                            vida += 2;
                                                            atk += 2;
                                                            def += 2;
                                                            
                                                        }
                                                        acaba = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                
                }
                    }
                }
                
                if((pokemon == 'c') && (escolha == 1) && (pokemonEnco == 1)){
                    if(nivel >= 7){
                        c7 = 1;
                        
                    }else{
                        if(nivel >= 13){
                            c13 = 1;
                            
                        }
                    }
                    
                    if(queimando == 1){
                        vidaAdv = vidaAdv - ((vidaAdv * 5)/ 100);
                        cout << "\nO Pokemon inimigo esta queimando\n";
                        cout << "\nO Pokemon inimigo agora tem " << vidaAdv << " de vida\n";
                    }
                    
                    if((c7 == 0) && (c13 == 0)){
                        cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n";
                        cin >> escolha;
                        
                        switch (escolha){
                            case 1:
                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                critico = 1+ rand() % 100;
                                
                                if(critico > 90){
                                    dano = dano * 1.5;
                                    cout << "\nO ataque foi critico!\n";
                                    
                                }
                                vidaAdv = vidaAdv - dano;
                                cout << "\nSeu Charmander ataca Rattata usando Scratch!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                            break;
                            
                            case 2: 
                                atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                cout << "\nSeu Charmander usou Growl\nAgora o ataque do Rattata e de " << atkAdv << " \n";
                            break;
                        }
                        if(vida <= 0){
                            queimando = 0;
                            cout << "\nVoce perdeu a batalha\n";
                            acaba = 1;
                            vida = vidaAux;
                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                            contGM = 0;
                            
                        }else{
                            if(vidaAdv <= 0){
                                queimando = 0;
                                cout << "\nVoce ganhou a batalha!!\n";
                                contNivel++;
                                if((contNivel % 2) == 0){
                                    nivel++;
                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                    vidaAux += 2;
                                    vida += 2;
                                    atk += 2;
                                    def += 2;
                                    
                                }
                                acaba = 1;
                                
                            }else{
                                cout << "\nAgora eh o turno do seu oponente!\n";
                                
                                decidirAdv = 1+ rand() % 2;
                                switch (decidirAdv){
                                    case 1:
                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                            
                                        }
                                        vida = vida - dano;
                                        cout << "\nO Rattata selvagem ataca seu Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                    break;
                                   
                                    case 2:
                                        def = def - ((def * 10) / 100);
                                        cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Charmander e de " << def << " \n";
                                        
                                    break;
                                    
                                    
                                }
                                if(vida <= 0){
                                    queimando = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        queimando = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                    }
                                }
                            }
                        }
                    }else{
                        if((c7 == 1) && (c13 == 0)){
                            cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n";
                            cin >> escolha;
                            
                            switch (escolha){
                                case 1:
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Charmander ataca Rattata usando Scratch!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                break;
                                
                                case 2: 
                                    atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                    cout << "\nSeu Charmander usou Growl\nAgora o ataque do Rattata e de " << atkAdv << " \n";
                                break;
                                
                                case 3:
                                    escolha = 0;
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    queimar = 1+ rand() % 100;
                                    if(queimar >= 90){
                                        queimando = 1;
                                        cout << "\nO Pokemon inimigo comecou a pegar fogo\n";
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Charmander ataca Rattata usando Ember!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                break;
                            }
                            if(vida <= 0){
                                queimando = 0;
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                                
                            }else{
                                if(vidaAdv <= 0){
                                    queimando = 0;
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                        
                                    }
                                    acaba = 1;
                                    
                                }else{
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Rattata selvagem ataca seu Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                        break;
                                       
                                        case 2:
                                            def = def - ((def * 10) / 100);
                                            cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Charmander e de " << def << " \n";
                                            
                                        break;
                                        
                                     
                                    }
                                    if(vida <= 0){
                                        queimando = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            queimando = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }
                            }  
                        }else{
                            if((c7 == 1) && (c13 == 1)){
                                cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scracth\n2 - Growl\n3 - Ember\n4 - Metal Claw\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Charmander ataca Rattata usando Scratch!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                        cout << "\nSeu Charmander usou Growl\nAgora o ataque do Rattata e de " << atkAdv << " \n";
                                    break;
                                    
                                    case 3:
                                        escolha = 0;
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        queimar = 1+ rand() % 100;
                                        if(queimar >= 90){
                                            queimando = 1;
                                            cout << "\nO Pokemon inimigo comecou a pegar fogo\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Charmander ataca Rattata usando Ember!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 4:
                                        dano = (((((2 * nivel / 5) + 2) * 50 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Charmander ataca Rattata usando Metal Claw!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                }
                                if(vida <= 0){
                                    queimando = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        queimando = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Rattata selvagem ataca seu Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                            break;
                                           
                                            case 2:
                                                def = def - ((def * 10) / 100);
                                                cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Charmander e de " << def << " \n";
                                                
                                            break;
                                            
                                         
                                        }
                                        if(vida <= 0){
                                            queimando = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                queimando = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }else{
                    if((pokemon == 'c') && (escolha == 1) && (pokemonEnco == 2)){
                        if(nivel >= 7){
                            c7 = 1;
                            
                        }else{
                            if(nivel >= 13){
                                c13 = 1;
                                
                            }
                        }
                        
                        if(queimando == 1){
                            vidaAdv = vidaAdv - ((vidaAdv * 5)/ 100);
                            cout << "\nO Pokemon inimigo esta queimando\n";
                            cout << "\nA vida dele agora e de " << vidaAdv << "\n";
                        }
                        
                        if((c7 == 0) && (c13 == 0)){
                            cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n";
                            cin >> escolha;
                            
                            switch (escolha){
                                case 1:
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Charmander ataca Pidgey usando Scratch!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                break;
                                
                                case 2: 
                                    atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                    cout << "\nSeu Charmander usou Growl\nAgora o ataque do Pidgey e de " << atkAdv << " \n";
                                break;
                            }
                            if(vida <= 0){
                                queimando = 0;
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                             
                            }else{
                                if(vidaAdv <= 0){
                                    queimando = 0;
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                        
                                    }
                                    acaba = 1;
                                    
                                }else{
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Pidgey selvagem ataca seu Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                        break;
                                       
                                        case 2:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                            
                                        break;
                                        
                                        
                                    }
                                    if(vida <= 0){
                                        queimando = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            queimando = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }
                            }
                        }else{
                            if((c7 == 1) && (c13 == 0)){
                                cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Charmander ataca Pidgey usando Scratch!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                        cout << "\nSeu Charmander usou Growl\nAgora o ataque do Pidgey e de " << atkAdv << " \n";
                                    break;
                                    
                                    case 3:
                                        escolha = 0;
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        queimar = 1+ rand() % 100;
                                        if(queimar >= 90){
                                            queimando = 1;
                                            cout << "\nO Pokemon inimigo comecou a queimar\n";
                                            
                                        }
                                        
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Charmander ataca Pidgey usando Ember!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                    break;
                                }
                                if(vida <= 0){
                                    queimando = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        queimando = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Pidgey selvagem ataca seu Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                    
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                
                                            break;
                                            
                                         
                                        }
                                        if(vida <= 0){
                                            queimando = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                queimando = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }  
                            }else{
                                if((c7 == 1) && (c13 == 1)){
                                    cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n4 - Metal Claw\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Charmander ataca Pidgey usando Scratch!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                            cout << "\nSeu Charmander usou Growl\nAgora o ataque do Pidgey e de " << atkAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            queimar = 1+ rand() % 100;
                                            if(queimar >= 90){
                                                queimando = 1;
                                                cout << "\nO Pokemon inimigo comecou a queimar\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Charmander ataca Pidgey usando Ember!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 4:
                                            dano = (((((2 * nivel / 5) + 2) * 50 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Charmander ataca Pidgey usando Metal Claw!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                    }
                                    if(vida <= 0){
                                        queimando = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            queimando = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                            
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1+ rand() % 2;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pidgey selvagem ataca seu Charmander usando Tackle!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                    
                                                break;
                                             
                                             
                                            }
                                            if(vida <= 0){
                                                queimando = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    queimando = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }else{
                        if((pokemon == 'c') && (escolha == 1) && (pokemonEnco == 3)){
                            if(nivel >= 7){
                                c7 = 1;
                                
                            }else{
                                if(nivel >= 13){
                                    c13 = 1;
                                    
                                }
                            }
                            
                            if(queimando == 1){
                                vidaAdv = vidaAdv - ((vidaAdv * 5)/ 100);
                                cout << "\nO Pokemon inimigo esta queimando\n";
                                cout << "\nA vida dele agora e de " << vidaAdv << "\n";
                            }
                            
                            if((c7 == 0) && (c13 == 0)){
                                cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Charmander ataca Growlithe usando Scratch!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                        cout << "\nSeu Charmander usou Growl\nAgora o ataque do Growlithe e de " << atkAdv << " \n";
                                    break;
                                }
                                if(vida <= 0){
                                    queimando = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        queimando = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                         
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Growlithe selvagem ataca seu Charmander usando Bite!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                dano = dano * 0.5;
                                                cout << "\nO atque nao foi muito efetivo\n";
                                                vida = vida - dano;
                                                cout << "\nO Growlithe selvagem ataca seu Charmander usando Ember!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                            break;
                                            
                                            
                                        }
                                        if(vida <= 0){
                                            queimando = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                queimando = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }
                            }else{
                                if((c7 == 1) && (c13 == 0)){
                                    cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Charmander ataca Growlithe usando Scratch!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                            cout << "\nSeu Charmander usou Growl\nAgora o ataque do Growlithe e de " << atkAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            dano = dano * 0.5;
                                            cout << "\nO ataque nao e muito efetivo\n";
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Charmander ataca Growlithe usando Ember!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                        break;
                                    }
                                    if(vida <= 0){
                                        queimando = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            queimando = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                         
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1+ rand() % 2;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Growlithe selvagem ataca seu Charmander usando Bite!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    dano = dano * 0.5;
                                                    cout << "\nO ataque nao e muito efetivo\n";
                                                    vida = vida - dano;
                                                    cout << "\nO Growlithe selvagem ataca seu Charmander usando Ember!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                    
                                                break;
                                                
                                             
                                            }
                                            if(vida <= 0){
                                                queimando = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    queimando = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }  
                                }else{
                                    if((c7 == 1) && (c13 == 1)){
                                        cout << "\nEscolha um ataque para seu Squirtle usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n4 - Metal Claw\n";
                                        cin >> escolha;
                                        
                                        switch (escolha){
                                            case 1:
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Charmander ataca Growlithe usando Scratch!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 2: 
                                                atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                                cout << "\nSeu Charmander usou Growl\nAgora o ataque do Growlithe e de " << atkAdv << " \n";
                                            break;
                                            
                                            case 3:
                                                escolha = 0;
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                dano = dano * 0.5;
                                                cout << "\nO ataque nao e muito efetivo\n";
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Charmander ataca Growlithe usando Ember!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 4:
                                                dano = (((((2 * nivel / 5) + 2) * 50 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico\n";
                                                
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Charmander ataca Growlithe usando Metal Claw!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                        }
                                        if(vida <= 0){
                                            queimando = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                queimando = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            
                                            }else{
                                                cout << "\nAgora eh o turno do seu oponente!\n";
                                                
                                                decidirAdv = 1+ rand() % 2;
                                                switch (decidirAdv){
                                                    case 1:
                                                        dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                                        critico = 1+ rand() % 100;
                                                        
                                                        if(critico > 90){
                                                            dano = dano * 1.5;
                                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                                            
                                                        }
                                                        vida = vida - dano;
                                                        cout << "\nO Growlithe selvagem ataca seu Charmander usando Bite!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                    break;
                                                    
                                                    case 2:
                                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                        critico = 1+ rand() % 100;
                                                        
                                                        if(critico > 90){
                                                            dano = dano * 1.5;
                                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                                            
                                                        }
                                                        dano = dano * 0.5;
                                                        cout << "\nO ataque nao e muito efetivozn";
                                                        vida = vida - dano;
                                                        cout << "\nO Growlithe selvagem ataca seu Charmander usando Ember!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                        
                                                    break;
                                                    
                                                 
                                                }
                                                if(vida <= 0){
                                                    queimando = 0;
                                                    cout << "\nVoce perdeu a batalha\n";
                                                    acaba = 1;
                                                    vida = vidaAux;
                                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                    contGM = 0;
                                                    
                                                }else{
                                                    if(vidaAdv <= 0){
                                                        queimando = 0;
                                                        cout << "\nVoce ganhou a batalha!!\n";
                                                        contNivel++;
                                                        if((contNivel % 2) == 0){
                                                            nivel++;
                                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                            vidaAux += 2;
                                                            vida += 2;
                                                            atk += 2;
                                                            def += 2;
                                                            
                                                        }
                                                        acaba = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }else{
                            if((pokemon == 'c') && (escolha == 1) && (pokemonEnco == 4)){
                                if(nivel >= 7){
                                    c7 = 1;
                                 
                                }else{
                                    if(nivel >= 13){
                                        c13 = 1;
                                        
                                    }
                                }
                                
                                if(queimando == 1){
                                    vidaAdv = vidaAdv - ((vidaAdv * 5)/ 100);
                                    cout << "\nO Pokemon inimigo esta queimando\n";
                                    cout << "\nA vida dele agora e de " << vidaAdv << "\n";
                                }
                                if((s7 == 0) && (s13 == 0)){
                                    cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n";
                                    cin >> escolha;
                                    
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Charmander ataca Abra usando Scratch!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                    atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                    cout << "\nSeu Charmander usou Growl\nAgora o ataque do Abra e de " << atkAdv << " \n";
                                    break;
                                }
                                if(vida <= 0){
                                    queimando = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        queimando = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                         
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1;
                                        switch (decidirAdv){
                                            case 1:
                                            cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                            vidaAdv = 0;
                                            break;
                                            
                                            
                                        }
                                        if(vida <= 0){
                                            queimando = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                queimando = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }
                            }else{
                                if((c7 == 1) && (c13 == 0)){
                                    cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                                if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Charmander ataca Abra usando Scratch!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                            cout << "\nSeu Charmander usou Growl\nAgora o ataque do Abra e de " << atkAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            queimar = 1+ rand() % 100;
                                            if(queimar >= 90){
                                                queimando = 1;
                                                cout << "\nO Pokemon inimigo comecou a queimar\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Charmander ataca Abra usando Ember!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                        break;
                                    }
                                    if(vida <= 0){
                                        queimando = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            queimando = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                         
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1;
                                            switch (decidirAdv){
                                                case 1:
                                                cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                                vidaAdv = 0;
                                                break;
                                                
                                             
                                            }
                                            if(vida <= 0){
                                                queimando = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    queimando = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }  
                                }else{
                                    if((c7 == 1) && (c13 == 1)){
                                        cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n4 - Metal Claw\n";
                                        cin >> escolha;
                                        
                                        switch (escolha){
                                            case 1:
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Charmander ataca Abra usando Scratch!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 2: 
                                                atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                                cout << "\nSeu Charmander usou Growl\nAgora o ataque do Abra e de " << atkAdv << " \n";
                                            break;
                                            
                                            case 3:
                                                escolha = 0;
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                queimar = 1+ rand() % 100;
                                                if(queimar >= 90){
                                                    queimando = 1;
                                                    cout << "\n O Pokemon de seu inimigo comecou a queimar\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Charmander ataca Abra usando Ember!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 4:
                                                dano = (((((2 * nivel / 5) + 2) * 50 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico\n";
                                                
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Charmander ataca Abra usando Metal Claw!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                        }
                                        if(vida <= 0){
                                            queimando = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                queimando = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                                
                                            }else{
                                                cout << "\nAgora eh o turno do seu oponente!\n";
                                                
                                                decidirAdv = 1;
                                                switch (decidirAdv){
                                                    case 1:
                                                    cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                                    vidaAdv = 0;
                                                    break;
                                                    
                                                 
                                                }
                                                if(vida <= 0){
                                                    queimando = 0;
                                                    cout << "\nVoce perdeu a batalha\n";
                                                    acaba = 1;
                                                    vida = vidaAux;
                                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                    contGM = 0;
                                                    
                                                }else{
                                                    if(vidaAdv <= 0){
                                                        queimando = 0;
                                                        cout << "\nVoce ganhou a batalha!!\n";
                                                        contNivel++;
                                                        if((contNivel % 2) == 0){
                                                            nivel++;
                                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                            vidaAux += 2;
                                                            vida += 2;
                                                            atk += 2;
                                                            def += 2;
                                                            
                                                        }
                                                        acaba = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }else{
                            if((pokemon == 'c') && (escolha == 1) && (pokemonEnco == 5)){
                                if(nivel >= 7){
                                    c7 = 1;
                                    
                                }else{
                                    if(nivel >= 13){
                                        c13 = 1;
                                        
                                    }
                                }
                                
                                if(queimando == 1){
                                    vidaAdv = vidaAdv - ((vidaAdv * 5)/ 100);
                                    cout << "\nO Pokemon inimigo esta queimando\n";
                                    cout << "\nA vida dele agora e de " << vidaAdv << "\n";
                                }
                                
                                if((c7 == 0) && (c13 == 0)){
                                    cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Charmander ataca Pikachu usando Scratch!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                        cout << "\nSeu Charmander udsou Growl\nAgora o ataque do Pikachu e de " << atkAdv << " \n";
                                        break;
                                    }
                                    if(vida <= 0){
                                        queimando = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            queimando = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                             
                                            }
                                            acaba = 1;
                                            
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pikachu selvagem ataca seu Charmander usando Thundershock!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    atk = atk - ((atk * 10) / 100);
                                                    cout << "\nO Pikachu usou Growl!\nAgora o ataque do Charmander e de " << atk << " \n";
                                                break;
                                                
                                                case 3:
                                                    def = def - ((def * 10) / 100);
                                                    cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Charmander e de " << def << " \n";
                                                break;
                                                
                                                
                                            }
                                            if(vida <= 0){
                                                queimando = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    queimando = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }
                                }else{
                                    if((c7 == 1) && (c13 == 0)){
                                        cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n";
                                        cin >> escolha;
                                        
                                        switch (escolha){
                                            case 1:
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                    if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Charmander ataca Pikachu usando Scratch!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 2: 
                                                atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                                cout << "\nSeu Charmander usou Growl!\nAgora o ataque do Pikachu e de " << atkAdv << " \n";
                                            break;
                                            
                                            case 3:
                                                escolha = 0;
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                queimar = 1+ rand() % 100;
                                                if(queimar >= 90){
                                                    queimando = 1;
                                                    cout << "\nO Pokemon inimigo comecou a queimar\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Charmander ataca Piakchu usando Ember!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                            break;
                                        }
                                        if(vida <= 0){
                                            queimando = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                queimando = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                             
                                            }else{
                                                cout << "\nAgora eh o turno do seu oponente!\n";
                                                
                                                decidirAdv = 1;
                                                switch (decidirAdv){
                                                    case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pikachu selvagem ataca seu Charmander usando Thundershock!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    atk = atk - ((atk * 10) / 100);
                                                    cout << "\nO Pikachu usou Growl!\nAgora o ataque do Charmander e de " << atk << " \n";
                                                break;
                                                
                                                case 3:
                                                    def = def - ((def * 10) / 100);
                                                    cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Charmander e de " << def << " \n";
                                                break;
                                                    
                                                 
                                                }
                                                if(vida <= 0){
                                                    queimando = 0;
                                                    cout << "\nVoce perdeu a batalha\n";
                                                    acaba = 1;
                                                    vida = vidaAux;
                                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                    contGM = 0;
                                                    
                                                }else{
                                                    if(vidaAdv <= 0){
                                                        queimando = 0;
                                                        cout << "\nVoce ganhou a batalha!!\n";
                                                        contNivel++;
                                                        if((contNivel % 2) == 0){
                                                            nivel++;
                                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                            vidaAux += 2;
                                                            vida += 2;
                                                            atk += 2;
                                                            def += 2;
                                                            
                                                        }
                                                        acaba = 1;
                                                    }
                                                }
                                            }
                                        }  
                                    }else{
                                        if((c7 == 1) && (c13 == 1)){
                                            cout << "\nEscolha um ataque para seu Charmander usar:\n1 - Scratch\n2 - Growl\n3 - Ember\n4 - Metal Claw\n";
                                            cin >> escolha;
                                            
                                            switch (escolha){
                                                case 1:
                                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque foi critico!\n";
                                                        
                                                    }
                                                    vidaAdv = vidaAdv - dano;
                                                    cout << "\nSeu Charmander ataca Pikachu usando Scratch!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                                break;
                                                
                                                case 2: 
                                                    atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                                    cout << "\nSeu Charmander usou Growl\nAgora o ataque do Pikachu e de " << atkAdv << " \n";
                                                break;
                                                
                                                case 3:
                                                    escolha = 0;
                                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque foi critico!\n";
                                                        
                                                    }
                                                    queimar = 1+ rand() % 100;
                                                    if(queimar >= 90){
                                                        queimando = 1;
                                                        cout << "\nO Pokemon inimigo comcou a queimar\n";
                                                        
                                                    }
                                                    vidaAdv = vidaAdv - dano;
                                                    cout << "\nSeu Charmander ataca Pikachu usando Ember!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                                break;
                                                
                                                case 4:
                                                    dano = (((((2 * nivel / 5) + 2) * 50 * atk) / defAdv) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque foi critico\n";
                                                        
                                                    }
                                                    vidaAdv = vidaAdv - dano;
                                                    cout << "\nSeu Charmander ataca Pikachu usando Metal Claw!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                                break;
                                                
                                            }
                                            if(vida <= 0){
                                                queimando = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    queimando = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                    
                                                }else{
                                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                                    
                                                    decidirAdv = 1;
                                                    switch (decidirAdv){
                                                        case 1:
                                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                            critico = 1+ rand() % 100;
                                                            
                                                            if(critico > 90){
                                                                dano = dano * 1.5;
                                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                                
                                                            }
                                                            vida = vida - dano;
                                                            cout << "\nO Pikachu selvagem ataca seu Charmander usando Thundershock!\nO ataque causou " << dano << " de dano\nCharmander agora esta com " << vida << "\n";
                                                        break;
                                                        
                                                        case 2:
                                                            atk = atk - ((atk * 10) / 100);
                                                            cout << "\nO Pikachu usou Growl!\nAgora o ataque do Charmander e de " << atk << " \n";
                                                        break;
                                                        
                                                        case 3:
                                                            def = def - ((def * 10) / 100);
                                                            cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Charmander e de " << def << " \n";
                                                        break;
                                                        
                                                     
                                                    }
                                                    if(vida <= 0){
                                                        queimando = 0;
                                                        cout << "\nVoce perdeu a batalha\n";
                                                        acaba = 1;
                                                        vida = vidaAux;
                                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                        contGM = 0;
                                                        
                                                    }else{
                                                        if(vidaAdv <= 0){
                                                            queimando = 0;
                                                            cout << "\nVoce ganhou a batalha!!\n";
                                                            contNivel++;
                                                            if((contNivel % 2) == 0){
                                                                nivel++;
                                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                                vidaAux += 2;
                                                                vida += 2;
                                                                atk += 2;
                                                                def += 2;
                                                                
                                                            }
                                                            acaba = 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        
                    
                    }
                        }
                }
                
                if((pokemon == 'b') && (escolha == 1) && (pokemonEnco == 1)){
                    if(nivel >= 7){
                        b7 = 1;
                        
                    }else{
                        if(nivel >= 13){
                            b13 = 1;
                            
                        }
                    }
                    
                    if(lS == 1){
                        vida = vida + ((vidaAdv * 12.5)/ 100);
                        vidaAdv = vidaAdv - ((vidaAdv * 12.5)/ 100);
                        cout << "\nA semente plantada no Pokemon inimigo drenou sua vida\n";
                        cout << "\nO Pokemon inimigo agora tem " << vidaAdv << " de vida\n";
                    }
                    
                    if((b7 == 0) && (b13 == 0)){
                        cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n";
                        cin >> escolha;
                        
                        switch (escolha){
                            case 1:
                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                critico = 1+ rand() % 100;
                                
                                if(critico > 90){
                                    dano = dano * 1.5;
                                    cout << "\nO ataque foi critico!\n";
                                    
                                }
                                vidaAdv = vidaAdv - dano;
                                cout << "\nSeu Bulbasaur ataca Rattata usando Tackle!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                            break;
                            
                            case 2: 
                                atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Rattata e de " << atkAdv << " \n";
                            break;
                        }
                        if(vida <= 0){
                            lS = 0;
                            cout << "\nVoce perdeu a batalha\n";
                            acaba = 1;
                            vida = vidaAux;
                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                            contGM = 0;
                            
                        }else{
                            if(vidaAdv <= 0){
                                lS = 0;
                                cout << "\nVoce ganhou a batalha!!\n";
                                contNivel++;
                                if((contNivel % 2) == 0){
                                    nivel++;
                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                    vidaAux += 2;
                                    vida += 2;
                                    atk += 2;
                                    def += 2;
                                    
                                }
                                acaba = 1;
                                
                            }else{
                                cout << "\nAgora eh o turno do seu oponente!\n";
                                
                                decidirAdv = 1+ rand() % 2;
                                switch (decidirAdv){
                                    case 1:
                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                            
                                        }
                                        vida = vida - dano;
                                        cout << "\nO Rattata selvagem ataca seu Bulbasaur usando Tackle!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                    break;
                                   
                                    case 2:
                                        def = def - ((def * 10) / 100);
                                        cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Bulbasaur e de " << def << " \n";
                                        
                                    break;
                                    
                                    
                                }
                                if(vida <= 0){
                                    lS = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        lS = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                    }
                                }
                            }
                        }
                    }else{
                        if((b7 == 1) && (b13 == 0)){
                            cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n";
                            cin >> escolha;
                            
                            switch (escolha){
                                case 1:
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Bulbasaur ataca Rattata usando Tackle!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                break;
                                
                                case 2: 
                                    atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                    cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Rattata e de " << atkAdv << " \n";
                                break;
                                
                                case 3:
                                    escolha = 0;
                                    lS = 1;
                                    cout << "\nSeu Bulbasaur ataca Rattata usando Leech Seed!\nUma semente foi plantada em Rattata\n";
                                break;
                            }
                            if(vida <= 0){
                                lS = 0;
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                                
                            }else{
                                if(vidaAdv <= 0){
                                    lS = 0;
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                        
                                    }
                                    acaba = 1;
                                    
                                }else{
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Rattata selvagem ataca seu Bulbasaur usando Tackle!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                        break;
                                       
                                        case 2:
                                            def = def - ((def * 10) / 100);
                                            cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Bulbasaur e de " << def << " \n";
                                            
                                        break;
                                        
                                     
                                    }
                                    if(vida <= 0){
                                        lS = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            lS = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }
                            }  
                        }else{
                            if((b7 == 1) && (b13 == 1)){
                                cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n4 - Vine Whip\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Bulbasaur ataca Rattata usando Tackle!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                        cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Rattata e de " << atkAdv << " \n";
                                    break;
                                    
                                    case 3:
                                        escolha = 0;
                                        lS = 1;
                                        cout << "\nSeu Bulbasaur ataca Rattata usando Leech Seed!\nUma Semente foi plantada em Rattata\n";
                                    break;
                                    
                                    case 4:
                                        dano = (((((2 * nivel / 5) + 2) * 35 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Bulbasaur ataca Rattata usando Vine Whip!\nO ataque causou " << dano << " de dano\nRattata agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                }
                                if(vida <= 0){
                                    lS = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        lS = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Rattata selvagem ataca seu Bulbasaur usando Tackle!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                            break;
                                           
                                            case 2:
                                                def = def - ((def * 10) / 100);
                                                cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Bulbasaur e de " << def << " \n";
                                                
                                            break;
                                            
                                         
                                        }
                                        if(vida <= 0){
                                            lS = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                lS = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }else{
                    if((pokemon == 'b') && (escolha == 1) && (pokemonEnco == 2)){
                        if(nivel >= 7){
                            b7 = 1;
                            
                        }else{
                            if(nivel >= 13){
                                b13 = 1;
                                
                            }
                        }
                        
                        if(lS == 1){
                            vida = vida + ((vidaAdv * 12.5)/ 100);
                            vidaAdv = vidaAdv - ((vidaAdv * 12.5)/ 100);
                            cout << "\nA semente plantada no Pokemon inimigo drenou sua vida\n";
                            cout << "\nO Pokemon inimigo agora tem " << vidaAdv << " de vida\n";
                        }
                        
                        if((b7 == 0) && (b13 == 0)){
                            cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n";
                            cin >> escolha;
                            
                            switch (escolha){
                                case 1:
                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque foi critico!\n";
                                        
                                    }
                                    vidaAdv = vidaAdv - dano;
                                    cout << "\nSeu Bulbasaur ataca Pidgey usando Tackle!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                break;
                                
                                case 2: 
                                    atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                    cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Pidgey e de " << atkAdv << " \n";
                                break;
                            }
                            if(vida <= 0){
                                lS = 0;
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                             
                            }else{
                                if(vidaAdv <= 0){
                                    lS = 0;
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                        
                                    }
                                    acaba = 1;
                                    
                                }else{
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Pidgey selvagem ataca seu Bulbasaur usando Tackle!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                        break;
                                       
                                        case 2:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                            
                                        break;
                                        
                                        
                                    }
                                    if(vida <= 0){
                                        lS = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            lS = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }
                            }
                        }else{
                            if((b7 == 1) && (b13 == 0)){
                                cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Bulbasaur ataca Pidgey usando Tackle!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                        cout << "\nSeu Charmander usou Growl\nAgora o ataque do Pidgey e de " << atkAdv << " \n";
                                    break;
                                    
                                    case 3:
                                        escolha = 0;
                                        lS = 1;
                                        cout << "\nSeu Bulbasaur ataca Pidgey usando Leech Seed!\nUma semente foi plantada em Pidgey\n";
                                    break;
                                }
                                if(vida <= 0){
                                    lS = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        lS = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Pidgey selvagem ataca seu Bulbasaur usando Tackle!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                    
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                
                                            break;
                                            
                                         
                                        }
                                        if(vida <= 0){
                                            lS = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                lS = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }  
                            }else{
                                if((b7 == 1) && (b13 == 1)){
                                    cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n4 - Vine Whip\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Bulbasaur ataca Pidgey usando Tackle!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                            cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Pidgey e de " << atkAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            lS = 1;
                                            cout << "\nSeu Bulbasaur ataca Pidgey usando Leech Seed!\nUma semente foi plantada em Pidgey\n";
                                        break;
                                        
                                        case 4:
                                            dano = (((((2 * nivel / 5) + 2) * 35 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Bulbasaur ataca Pidgey usando Vine Whip!\nO ataque causou " << dano << " de dano\nPidgey agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                    }
                                    if(vida <= 0){
                                        lS = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            lS = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                            
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1+ rand() % 2;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pidgey selvagem ataca seu Bulbasaur usando Tackle!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                    
                                                break;
                                             
                                             
                                            }
                                            if(vida <= 0){
                                                lS = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    lS = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }else{
                        if((pokemon == 'b') && (escolha == 1) && (pokemonEnco == 3)){
                            if(nivel >= 7){
                                b7 = 1;
                                
                            }else{
                                if(nivel >= 13){
                                    b13 = 1;
                                    
                                }
                            }
                            
                            if(lS == 1){
                                vida = vida + ((vidaAdv * 12.5)/ 100);
                                vidaAdv = vidaAdv - ((vidaAdv * 12.5)/ 100);
                                cout << "\nA semente plantada no Pokemon inimigo drenou sua vida\n";
                                cout << "\nO Pokemon inimigo agora tem " << vidaAdv << " de vida\n";
                            }
                            
                            if((b7 == 0) && (b13 == 0)){
                                cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n";
                                cin >> escolha;
                                
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Bulbasaur ataca Growlithe usando Tackle!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                        cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Growlithe e de " << atkAdv << " \n";
                                    break;
                                }
                                if(vida <= 0){
                                    lS = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        lS = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                         
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1+ rand() % 2;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Growlithe selvagem ataca seu Bulbasaur usando Bite!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                dano = dano * 2;
                                                cout << "\nO ataque foi super efetivo\n";
                                                vida = vida - dano;
                                                cout << "\nO Growlithe selvagem ataca seu Bulbasaur usando Ember!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                            break;
                                            
                                            
                                        }
                                        if(vida <= 0){
                                            lS = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                lS = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }
                            }else{
                                if((b7 == 1) && (b13 == 0)){
                                    cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Bulbasaur ataca Growlithe usando Tackle!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                            cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Growlithe e de " << atkAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            lS = 1;
                                            cout << "\nSeu Bulbasaur ataca Growlithe usando Leech Seed!\nUma semente foi plantada em Growlithe\n";
                                        break;
                                    }
                                    if(vida <= 0){
                                        lS = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            lS = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                         
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1+ rand() % 2;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Growlithe selvagem ataca seu Bulbasaur usando Bite!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    dano = dano * 2;
                                                    cout << "\nO ataque eh super efetivo\n";
                                                    vida = vida - dano;
                                                    cout << "\nO Growlithe selvagem ataca seu Bulbasaur usando Ember!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                    
                                                break;
                                                
                                             
                                            }
                                            if(vida <= 0){
                                                lS = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    lS = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }  
                                }else{
                                    if((b7 == 1) && (b13 == 1)){
                                        cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n4 - Vine Whip\n";
                                        cin >> escolha;
                                        
                                        switch (escolha){
                                            case 1:
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Bulbasaur ataca Growlithe usando Tackle!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 2: 
                                                atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                                cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Growlithe e de " << atkAdv << " \n";
                                            break;
                                            
                                            case 3:
                                                escolha = 0;
                                                lS = 1;
                                                cout << "\nSeu Bulbasaur ataca Growlithe usando Leech Seed!\nUma semente foi plantada em Growlithe\n";
                                            break;
                                            
                                            case 4:
                                                dano = (((((2 * nivel / 5) + 2) * 35 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico\n";
                                                
                                                }
                                                dano = dano * 0.5;
                                                cout << "\nO ataque nao eh efetivo contra fogo\n";
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Bulbasaur ataca Growlithe usando Vine Whip!\nO ataque causou " << dano << " de dano\nGrowlithe agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                        }
                                        if(vida <= 0){
                                            lS = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                lS = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            
                                            }else{
                                                cout << "\nAgora eh o turno do seu oponente!\n";
                                                
                                                decidirAdv = 1+ rand() % 2;
                                                switch (decidirAdv){
                                                    case 1:
                                                        dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                                        critico = 1+ rand() % 100;
                                                        
                                                        if(critico > 90){
                                                            dano = dano * 1.5;
                                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                                            
                                                        }
                                                        vida = vida - dano;
                                                        cout << "\nO Growlithe selvagem ataca seu Bulbasaur usando Bite!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                    break;
                                                    
                                                    case 2:
                                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                        critico = 1+ rand() % 100;
                                                        
                                                        if(critico > 90){
                                                            dano = dano * 1.5;
                                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                                            
                                                        }
                                                        dano = dano * 2;
                                                        cout << "\nO ataque eh super efetivo\n";
                                                        vida = vida - dano;
                                                        cout << "\nO Growlithe selvagem ataca seu Bulbasaur usando Ember!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                        
                                                    break;
                                                    
                                                 
                                                }
                                                if(vida <= 0){
                                                    lS = 0;
                                                    cout << "\nVoce perdeu a batalha\n";
                                                    acaba = 1;
                                                    vida = vidaAux;
                                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                    contGM = 0;
                                                    
                                                }else{
                                                    if(vidaAdv <= 0){
                                                        lS = 0;
                                                        cout << "\nVoce ganhou a batalha!!\n";
                                                        contNivel++;
                                                        if((contNivel % 2) == 0){
                                                            nivel++;
                                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                            vidaAux += 2;
                                                            vida += 2;
                                                            atk += 2;
                                                            def += 2;
                                                            
                                                        }
                                                        acaba = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }else{
                            if((pokemon == 'b') && (escolha == 1) && (pokemonEnco == 4)){
                                if(nivel >= 7){
                                    b7 = 1;
                                 
                                }else{
                                    if(nivel >= 13){
                                        b13 = 1;
                                        
                                    }
                                }
                                
                                if(lS == 1){
                                    vida = vida + ((vidaAdv * 12.5)/ 100);
                                    vidaAdv = vidaAdv - ((vidaAdv * 12.5)/ 100);
                                    cout << "\nA semente plantada no Pokemon inimigo drenou sua vida\n";
                                    cout << "\nO Pokemon inimigo agora tem " << vidaAdv << " de vida\n";
                                }
                                
                                if((b7 == 0) && (b13 == 0)){
                                    cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n";
                                    cin >> escolha;
                                    
                                switch (escolha){
                                    case 1:
                                        dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque foi critico!\n";
                                            
                                        }
                                        vidaAdv = vidaAdv - dano;
                                        cout << "\nSeu Bulbasaur ataca Abra usando Tackle!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                    break;
                                    
                                    case 2: 
                                    atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                    cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Abra e de " << atkAdv << " \n";
                                    break;
                                }
                                if(vida <= 0){
                                    lS = 0;
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        lS = 0;
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                         
                                        }
                                        acaba = 1;
                                        
                                    }else{
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1;
                                        switch (decidirAdv){
                                            case 1:
                                            cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                            vidaAdv = 0;
                                            break;
                                            
                                            
                                        }
                                        if(vida <= 0){
                                            lS = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                lS = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }
                                }
                            }else{
                                if((b7 == 1) && (b13 == 0)){
                                    cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                                if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Bulbasaur ataca Abra usando Tackle!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                            atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                            cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Abra e de " << atkAdv << " \n";
                                        break;
                                        
                                        case 3:
                                            escolha = 0;
                                            lS = 1;
                                            cout << "\nSeu Bulbasaur ataca Abra usando Leech Seed!\nUma semente foi plantada em Abra\n";
                                        break;
                                    }
                                    if(vida <= 0){
                                        lS = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            lS = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                         
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1;
                                            switch (decidirAdv){
                                                case 1:
                                                cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                                vidaAdv = 0;
                                                break;
                                                
                                             
                                            }
                                            if(vida <= 0){
                                                lS = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    lS = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }  
                                }else{
                                    if((b7 == 1) && (b13 == 1)){
                                        cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n4 - Vine Whip\n";
                                        cin >> escolha;
                                        
                                        switch (escolha){
                                            case 1:
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Bulbasaur ataca Abra usando Tackle!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 2: 
                                                atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                                cout << "\nSeu Charmander usou Growl\nAgora o ataque do Abra e de " << atkAdv << " \n";
                                            break;
                                            
                                            case 3:
                                                escolha = 0;
                                                lS = 1;
                                                cout << "\nSeu Bulbasaur ataca Abra usando Leech Seed!\nUma semente foi planatda em Abra\n";
                                            break;
                                            
                                            case 4:
                                                dano = (((((2 * nivel / 5) + 2) * 35 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico\n";
                                                
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Bulbasaur ataca Abra usando Vine Whip!\nO ataque causou " << dano << " de dano\nAbra agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                        }
                                        if(vida <= 0){
                                            lS = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                lS = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                                
                                            }else{
                                                cout << "\nAgora eh o turno do seu oponente!\n";
                                                
                                                decidirAdv = 1;
                                                switch (decidirAdv){
                                                    case 1:
                                                    cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                                    vidaAdv = 0;
                                                    break;
                                                    
                                                 
                                                }
                                                if(vida <= 0){
                                                    lS = 0;
                                                    cout << "\nVoce perdeu a batalha\n";
                                                    acaba = 1;
                                                    vida = vidaAux;
                                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                    contGM = 0;
                                                    
                                                }else{
                                                    if(vidaAdv <= 0){
                                                        lS = 0;
                                                        cout << "\nVoce ganhou a batalha!!\n";
                                                        contNivel++;
                                                        if((contNivel % 2) == 0){
                                                            nivel++;
                                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                            vidaAux += 2;
                                                            vida += 2;
                                                            atk += 2;
                                                            def += 2;
                                                            
                                                        }
                                                        acaba = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }else{
                            if((pokemon == 'b') && (escolha == 1) && (pokemonEnco == 5)){
                                if(nivel >= 7){
                                    b7 = 1;
                                    
                                }else{
                                    if(nivel >= 13){
                                        b13 = 1;
                                        
                                    }
                                }
                                
                                if(lS == 1){
                                    vida = vida + ((vidaAdv * 12.5)/ 100);
                                    vidaAdv = vidaAdv - ((vidaAdv * 12.5)/ 100);
                                    cout << "\nA semente plantada no Pokemon inimigo drenou sua vida\n";
                                    cout << "\nO Pokemon inimigo agora tem " << vidaAdv << " de vida\n";
                                }
                                
                                if((b7 == 0) && (b13 == 0)){
                                    cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n";
                                    cin >> escolha;
                                    
                                    switch (escolha){
                                        case 1:
                                            dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                            
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque foi critico!\n";
                                                
                                            }
                                            vidaAdv = vidaAdv - dano;
                                            cout << "\nSeu Bulbasaur ataca Pikachu usando Tackle!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                        break;
                                        
                                        case 2: 
                                        atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                        cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Pikachu e de " << atkAdv << " \n";
                                        break;
                                    }
                                    if(vida <= 0){
                                        lS = 0;
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            lS = 0;
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                             
                                            }
                                            acaba = 1;
                                            
                                        }else{
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pikachu selvagem ataca seu Bulbasaur usando Thundershock!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    atk = atk - ((atk * 10) / 100);
                                                    cout << "\nO Pikachu usou Growl!\nAgora o ataque do Bulbasaur e de " << atk << " \n";
                                                break;
                                                
                                                case 3:
                                                    def = def - ((def * 10) / 100);
                                                    cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Bulbasaur e de " << def << " \n";
                                                break;
                                                
                                                
                                            }
                                            if(vida <= 0){
                                                lS = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    lS = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }
                                }else{
                                    if((b7 == 1) && (b13 == 0)){
                                        cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n";
                                        cin >> escolha;
                                        
                                        switch (escolha){
                                            case 1:
                                                dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                    if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque foi critico!\n";
                                                    
                                                }
                                                vidaAdv = vidaAdv - dano;
                                                cout << "\nSeu Bulbasaur ataca Pikachu usando Tackle!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                            break;
                                            
                                            case 2: 
                                                atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                                cout << "\nSeu Bulbasaur usou Growl!\nAgora o ataque do Pikachu e de " << atkAdv << " \n";
                                            break;
                                            
                                            case 3:
                                                escolha = 0;
                                                lS = 1;
                                                cout << "\nSeu Bulbasaur ataca Piakchu usando Leech Seed!\nUma semente foi plantada em Pikachu\n";
                                            break;
                                        }
                                        if(vida <= 0){
                                            lS = 0;
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                lS = 0;
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                             
                                            }else{
                                                cout << "\nAgora eh o turno do seu oponente!\n";
                                                
                                                decidirAdv = 1;
                                                switch (decidirAdv){
                                                    case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pikachu selvagem ataca seu Bulbasaur usando Thundershock!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    atk = atk - ((atk * 10) / 100);
                                                    cout << "\nO Pikachu usou Growl!\nAgora o ataque do Bulbasaur e de " << atk << " \n";
                                                break;
                                                
                                                case 3:
                                                    def = def - ((def * 10) / 100);
                                                    cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Bulbasaur e de " << def << " \n";
                                                break;
                                                    
                                                 
                                                }
                                                if(vida <= 0){
                                                    lS = 0;
                                                    cout << "\nVoce perdeu a batalha\n";
                                                    acaba = 1;
                                                    vida = vidaAux;
                                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                    contGM = 0;
                                                    
                                                }else{
                                                    if(vidaAdv <= 0){
                                                        lS = 0;
                                                        cout << "\nVoce ganhou a batalha!!\n";
                                                        contNivel++;
                                                        if((contNivel % 2) == 0){
                                                            nivel++;
                                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                            vidaAux += 2;
                                                            vida += 2;
                                                            atk += 2;
                                                            def += 2;
                                                            
                                                        }
                                                        acaba = 1;
                                                    }
                                                }
                                            }
                                        }  
                                    }else{
                                        if((b7 == 1) && (b13 == 1)){
                                            cout << "\nEscolha um ataque para seu Bulbasaur usar:\n1 - Tackle\n2 - Growl\n3 - Leech Seed\n4 - Vine Whip\n";
                                            cin >> escolha;
                                            
                                            switch (escolha){
                                                case 1:
                                                    dano = (((((2 * nivel / 5) + 2) * 40 * atk) / defAdv) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque foi critico!\n";
                                                        
                                                    }
                                                    vidaAdv = vidaAdv - dano;
                                                    cout << "\nSeu Bulbasaur ataca Pikachu usando Tackle!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                                break;
                                                
                                                case 2: 
                                                    atkAdv = atkAdv - ((atkAdv * 10) / 100);
                                                    cout << "\nSeu Bulbasaur usou Growl\nAgora o ataque do Pikachu e de " << atkAdv << " \n";
                                                break;
                                                
                                                case 3:
                                                    escolha = 0;
                                                    lS = 1;
                                                    cout << "\nSeu Bulbasaur ataca Pikachu usando Leech Seed!\nUma semente foi plantada em Pikachu\n";
                                                break;
                                                
                                                case 4:
                                                    dano = (((((2 * nivel / 5) + 2) * 35 * atk) / defAdv) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque foi critico\n";
                                                        
                                                    }
                                                    vidaAdv = vidaAdv - dano;
                                                    cout << "\nSeu Bulbasaur ataca Pikachu usando Vine Whip!\nO ataque causou " << dano << " de dano\nPikachu agora esta com " << vidaAdv << "\n";
                                                break;
                                                
                                            }
                                            if(vida <= 0){
                                                lS = 0;
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    lS = 0;
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                    
                                                }else{
                                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                                    
                                                    decidirAdv = 1;
                                                    switch (decidirAdv){
                                                        case 1:
                                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                            critico = 1+ rand() % 100;
                                                            
                                                            if(critico > 90){
                                                                dano = dano * 1.5;
                                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                                
                                                            }
                                                            vida = vida - dano;
                                                            cout << "\nO Pikachu selvagem ataca seu Bulbasaur usando Thundershock!\nO ataque causou " << dano << " de dano\nBulbasaur agora esta com " << vida << "\n";
                                                        break;
                                                        
                                                        case 2:
                                                            atk = atk - ((atk * 10) / 100);
                                                            cout << "\nO Pikachu usou Growl!\nAgora o ataque do Bulbasaur e de " << atk << " \n";
                                                        break;
                                                        
                                                        case 3:
                                                            def = def - ((def * 10) / 100);
                                                            cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do Bulbasaur e de " << def << " \n";
                                                        break;
                                                        
                                                     
                                                    }
                                                    if(vida <= 0){
                                                        lS = 0;
                                                        cout << "\nVoce perdeu a batalha\n";
                                                        acaba = 1;
                                                        vida = vidaAux;
                                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                        contGM = 0;
                                                        
                                                    }else{
                                                        if(vidaAdv <= 0){
                                                            lS = 0;
                                                            cout << "\nVoce ganhou a batalha!!\n";
                                                            contNivel++;
                                                            if((contNivel % 2) == 0){
                                                                nivel++;
                                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                                vidaAux += 2;
                                                                vida += 2;
                                                                atk += 2;
                                                                def += 2;
                                                                
                                                            }
                                                            acaba = 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        
                    
                    }
                        }
                }

                
                if((pokebolas > 0) && (escolha == 2)){
                    if(pokemonEnco == 1){
                        cout << "\nVoce joga a Pokebola...\n";
                        chanceCaptura = ((((3 * vidaMax) - (2 * vidaAdv)) * taxaBase * 1) / (3 * vidaMax)) * 1;
                        if(chanceCaptura > 60){
                            cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                            cout << "\nO Rattata foi capturado com sucesso!\n";
                            acaba = 1;
                            pokebolas--;
                            
                        }else{
                            cout << "\nO Rattata fugiu da Pokebola\n";
                            pokebolas--;
                            
                            cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                            
                            cout << "\nAgora eh o turno do seu oponente!\n";
                            
                            decidirAdv = 1+ rand() % 2;
                            switch (decidirAdv){
                                case 1:
                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                        
                                    }
                                    vida = vida - dano;
                                    cout << "\nO Rattata selvagem ataca usando Tackle!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                break;
                                  
                                case 2:
                                    def = def - ((def * 10) / 100);
                                    cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Pokemon e de " << def << " \n";
                                    
                                break;
                                
                                
                            }
                            if(vida <= 0){
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                                
                            }else{
                                if(vidaAdv <= 0){
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                        
                                    }
                                    acaba = 1;
                                }
                            }
                            
                        }
                        
                    }else{
                        if(pokemonEnco == 2){
                            cout << "\nVoce joga a Pokebola...\n";
                            chanceCaptura = ((((3 * vidaMax) - (2 * vidaAdv)) * taxaBase * 1) / (3 * vidaMax)) * 1;
                            if(chanceCaptura > 60){
                                cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                                cout << "\nO Pidgey foi capturado com sucesso!\n";
                                acaba = 1;
                                pokebolas--;
                                
                            }else{
                                cout << "\nO Pidgey fugiu da Pokebola\n";
                                pokebolas--;
                                
                                cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                                
                                cout << "\nAgora eh o turno do seu oponente!\n";
                                
                                decidirAdv = 1+ rand() % 2;
                                switch (decidirAdv){
                                    case 1:
                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                            
                                        }
                                        vida = vida - dano;
                                        cout << "\nO Pidgey selvagem ataca seu Pokemon usando Tackle!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                    break;
                                    
                                    case 2:
                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                            
                                        }
                                        vida = vida - dano;
                                        cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                        
                                    break;
                                    
                                    
                                }
                                if(vida <= 0){
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                    }
                                }
                                
                            }
                            
                        }else{
                            if(pokemonEnco == 3){
                                cout << "\nVoce joga a Pokebola...\n";
                                chanceCaptura = ((((3 * vidaMax) - (2 * vidaAdv)) * taxaBase * 1) / (3 * vidaMax)) * 1;
                                if(chanceCaptura > 60){
                                    cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                                    cout << "\nO Growlithe foi capturado com sucesso!\n";
                                    acaba = 1;
                                    pokebolas--;
                                    
                                }else{
                                    cout << "\nO Growlithe fugiu da Pokebola\n";
                                    pokebolas--;
                                    
                                    cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                                    
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                         
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Growlithe selvagem ataca seu Pokemon usando Bite!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                        break;
                                        
                                        case 2:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                         
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Growlithe selvagem ataca seu Pokemon usando Ember!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                        break;
                                        
                                        
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                    
                                }
                                
                            }else{
                                if(pokemonEnco == 4){
                                    cout << "\nVoce joga a Pokebola...\n";
                                    chanceCaptura = ((((3 * vidaMax) - (2 * vidaAdv)) * taxaBase * 1) / (3 * vidaMax)) * 1;
                                    if(chanceCaptura > 60){
                                        cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                                        cout << "\nO Abra foi capturado com sucesso!\n";
                                        acaba = 1;
                                        pokebolas--;
                                        
                                    }else{
                                        cout << "\nO Abra fugiu da Pokebola\n";
                                        pokebolas--;
                                        
                                        cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                                        
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1;
                                        switch (decidirAdv){
                                            case 1:
                                                cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                                vidaAdv = 0;
                                            break;
                                            
                                            
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                        
                                    }
                                    
                                }else{
                                    cout << "\nVoce joga a Pokebola...\n";
                                    chanceCaptura = ((((3 * vidaMax) - (2 * vidaAdv)) * taxaBase * 1) / (3 * vidaMax)) * 1;
                                    if(chanceCaptura > 60){
                                        cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                                        cout << "\nO Pikachu foi capturado com sucesso!\n";
                                        acaba = 1;
                                        pokebolas--;
                                        
                                    }else{
                                        cout << "\nO Pikachu fugiu da Pokebola\n";
                                        pokebolas--;
                                        
                                        cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                                        
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1;
                                        switch (decidirAdv){
                                            case 1:
                                                dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                critico = 1+ rand() % 100;
                                                
                                                if(critico > 90){
                                                    dano = dano * 1.5;
                                                    cout << "\nO ataque de seu oponente foi critico!\n";
                                                    
                                                }
                                                vida = vida - dano;
                                                cout << "\nO Pikachu selvagem ataca seu Pokemon usando Thundershock!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                            break;
                                            
                                            case 2:
                                                atk = atk - ((atk * 10) / 100);
                                                cout << "\nO Pikachu usou Growl!\nAgora o ataque do seu Pokemon e de " << atk << " \n";
                                            break;
                                            
                                            case 3:
                                                def = def - ((def * 10) / 100);
                                                cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do seu Pokemon e de " << def << " \n";
                                            break;
                                            
                                            
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                }else{
                    if((pokebolas == 0) && (escolha == 2)){
                        cout << "\nVoce nao tem mais Pokebolas\n";
                        
                    }
                }
                
                if(escolha == 3){
                    fugir = 1+ rand() % 2;
                    if(fugir == 1){
                        cout << "\nVoce conseguiu fugir da batalha\n";
                        acaba = 1;
                        
                    }else{
                        cout << "\nVoce nao conseguiu fugir\n";
                        
                        if(pokemonEnco == 1){
                            cout << "\nAgora eh o turno do seu oponente!\n";
                            
                            decidirAdv = 1+ rand() % 2;
                            switch (decidirAdv){
                                case 1:
                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                    critico = 1+ rand() % 100;
                                    
                                    if(critico > 90){
                                        dano = dano * 1.5;
                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                        
                                    }
                                    vida = vida - dano;
                                    cout << "\nO Rattata selvagem ataca usando Tackle!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                break;
                                  
                                case 2:
                                    def = def - ((def * 10) / 100);
                                    cout << "\nO Rattata selvagem usou Tail Whip\nAgora a defesa de seu Pokemon e de " << def << " \n";
                                    
                                break;
                                
                                
                            }
                            if(vida <= 0){
                                cout << "\nVoce perdeu a batalha\n";
                                acaba = 1;
                                vida = vidaAux;
                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                contGM = 0;
                                
                            }else{
                                if(vidaAdv <= 0){
                                    cout << "\nVoce ganhou a batalha!!\n";
                                    contNivel++;
                                    if((contNivel % 2) == 0){
                                        nivel++;
                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                        vidaAux += 2;
                                        vida += 2;
                                        atk += 2;
                                        def += 2;
                                        
                                    }
                                    acaba = 1;
                                }
                            }
                        }else{
                            if(pokemonEnco == 2){
                                cout << "\nAgora eh o turno do seu oponente!\n";
                                
                                decidirAdv = 1+ rand() % 2;
                                switch (decidirAdv){
                                    case 1:
                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                            
                                        }
                                        vida = vida - dano;
                                        cout << "\nO Pidgey selvagem ataca seu Pokemon usando Tackle!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                    break;
                                    
                                    case 2:
                                        dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                        critico = 1+ rand() % 100;
                                        
                                        if(critico > 90){
                                            dano = dano * 1.5;
                                            cout << "\nO ataque de seu oponente foi critico!\n";
                                            
                                        }
                                        vida = vida - dano;
                                        cout << "\nO Pidgey selvagem usou Gust\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                        
                                    break;
                                    
                                    
                                }
                                if(vida <= 0){
                                    cout << "\nVoce perdeu a batalha\n";
                                    acaba = 1;
                                    vida = vidaAux;
                                    cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                    contGM = 0;
                                    
                                }else{
                                    if(vidaAdv <= 0){
                                        cout << "\nVoce ganhou a batalha!!\n";
                                        contNivel++;
                                        if((contNivel % 2) == 0){
                                            nivel++;
                                            cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                            vidaAux += 2;
                                            vida += 2;
                                            atk += 2;
                                            def += 2;
                                            
                                        }
                                        acaba = 1;
                                    }
                                }
                            }else{
                                if(pokemonEnco == 3){
                                    cout << "\nAgora eh o turno do seu oponente!\n";
                                    
                                    decidirAdv = 1+ rand() % 2;
                                    switch (decidirAdv){
                                        case 1:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 60 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                         
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Growlithe selvagem ataca seu Pokemon usando Bite!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                        break;
                                        
                                        case 2:
                                            dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                            critico = 1+ rand() % 100;
                                         
                                            if(critico > 90){
                                                dano = dano * 1.5;
                                                cout << "\nO ataque de seu oponente foi critico!\n";
                                                
                                            }
                                            vida = vida - dano;
                                            cout << "\nO Growlithe selvagem ataca seu Pokemon usando Ember!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                        break;
                                        
                                        
                                    }
                                    if(vida <= 0){
                                        cout << "\nVoce perdeu a batalha\n";
                                        acaba = 1;
                                        vida = vidaAux;
                                        cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                        contGM = 0;
                                        
                                    }else{
                                        if(vidaAdv <= 0){
                                            cout << "\nVoce ganhou a batalha!!\n";
                                            contNivel++;
                                            if((contNivel % 2) == 0){
                                                nivel++;
                                                cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                vidaAux += 2;
                                                vida += 2;
                                                atk += 2;
                                                def += 2;
                                                
                                            }
                                            acaba = 1;
                                        }
                                    }
                                }else{
                                    if(pokemonEnco == 4){
                                        cout << "\nAgora eh o turno do seu oponente!\n";
                                        
                                        decidirAdv = 1;
                                        switch (decidirAdv){
                                            case 1:
                                                cout << "\nO Abra usou Teleport!\nO Pokemon fugiu...\n";
                                                vidaAdv = 0;
                                            break;
                                            
                                            
                                        }
                                        if(vida <= 0){
                                            cout << "\nVoce perdeu a batalha\n";
                                            acaba = 1;
                                            vida = vidaAux;
                                            cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                            contGM = 0;
                                            
                                        }else{
                                            if(vidaAdv <= 0){
                                                cout << "\nVoce ganhou a batalha!!\n";
                                                contNivel++;
                                                if((contNivel % 2) == 0){
                                                    nivel++;
                                                    cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                    vidaAux += 2;
                                                    vida += 2;
                                                    atk += 2;
                                                    def += 2;
                                                    
                                                }
                                                acaba = 1;
                                            }
                                        }
                                    }else{
                                        if(pokemonEnco == 5){
                                            cout << "\nAgora eh o turno do seu oponente!\n";
                                            
                                            decidirAdv = 1;
                                            switch (decidirAdv){
                                                case 1:
                                                    dano = (((((2 * nivelAdv / 5) + 2) * 40 * atkAdv) / def) / 50) + 2;
                                                    critico = 1+ rand() % 100;
                                                    
                                                    if(critico > 90){
                                                        dano = dano * 1.5;
                                                        cout << "\nO ataque de seu oponente foi critico!\n";
                                                        
                                                    }
                                                    vida = vida - dano;
                                                    cout << "\nO Pikachu selvagem ataca seu Pokemon usando Thundershock!\nO ataque causou " << dano << " de dano\nSeu Pokemon agora esta com " << vida << "\n";
                                                break;
                                                
                                                case 2:
                                                    atk = atk - ((atk * 10) / 100);
                                                    cout << "\nO Pikachu usou Growl!\nAgora o ataque do seu Pokemon e de " << atk << " \n";
                                                break;
                                                
                                                case 3:
                                                    def = def - ((def * 10) / 100);
                                                    cout << "\nO Pikachu selvagem usou Tail Whip!\nAgora a defesa do seu Pokemon e de " << def << " \n";
                                                break;
                                                
                                                
                                            }
                                            if(vida <= 0){
                                                cout << "\nVoce perdeu a batalha\n";
                                                acaba = 1;
                                                vida = vidaAux;
                                                cout << "\nApos recuperar seu Pokemon no PokeCenter voce decide tentar novamente\n";
                                                contGM = 0;
                                                
                                            }else{
                                                if(vidaAdv <= 0){
                                                    cout << "\nVoce ganhou a batalha!!\n";
                                                    contNivel++;
                                                    if((contNivel % 2) == 0){
                                                        nivel++;
                                                        cout << "\nO seu Pokemon evoluiu um nivel!, agora estando no nivel " << nivel << "\n";
                                                        vidaAux += 2;
                                                        vida += 2;
                                                        atk += 2;
                                                        def += 2;
                                                        
                                                    }
                                                    acaba = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                
            }
            
            
        }else{
            cout << "\nNenhum Pokemon apareceu\n";
            
        }
    }
    
    
    cout << "\nParabens, Voce conseguiu chegar a Pewter City!!\n";
}







