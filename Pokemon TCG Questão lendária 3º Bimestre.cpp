/*Questão lendária 3°Bimestre planejamento:
A questão será como uma junção de yu-gi-oh com Pokemon TCG 
O jogo vai poder ser jogado por duas pessoa ou uma pessoa e um bot
as cartas recebidas vão ser definidas aleatoriamente
mostrar descrição das cartas recebidas a cada rodada
Os Decks ja vem pre definidos ( ainda vai ser planejado as cartas e os tipo e etc.) sendo um vetor de registros
cada pessoa terá um campo onde podera colocar 6 cartas no total, sendo 3 cartas de ataque e 3 cartas de suporte
as cartas de ataque vão ter estatiticas ( ataque, defesa e etc. ) e evolução
as cartas de ataque apenas poderão atacar outras cartas que estarão em sua frente, caso não tenha nenhuma o dano vai direto para o adversário
as cartas de ataque podem trocar de lugar umas com as outras (mas, ao mover seu pokemon, voce napo podera mais atacar nesta rodada)
voce apenas poderá atacar 1 vez por round
os ataques necessitarão de energia para conseguir atacar
as cartas de suporte serão usadas automaticamente ou manualmente (depende da carta)
é permitido por uma carta de suporte e usa-la no mesmo round
não é permitido por uma carta de ataque e atacar com ela no mesmo round
a cada round, cada jogador recebe a quantidade de energia equivalente a quantidade de cartas de ataque colocadas em seu campo
Pokemons deck fogo: Charmander, Charmeleon, Charizard, vulpix, ninetail, ponyta, rapidash, magmar, Pesquisa de professor, Blaine x2, Poção x2, Velocidade X
Deck agua: Squirtle, Wartortle, Blastoise, magikarp, gyarados, lapras, tentacool, tentacruel, pesquisa de professor, misty x2, poção x2, velocidade x
Deck Planta: Bulbasaur, Ivysaur, Venusaur, paras, parasect, exeggcute, exeggutor, pinsir, pesquisa de professor, Erika x2, poção x2, velocidade x
    cout << "\n\t\tCampo do oponente\n";
    for(i=0;i<2;i++){
        cout << "\n";
        for(j=0;j<5;j++){
            cout << "\t" << campo[j][i];
        }
    }
    cout << "\n\n\t\tSeu campo";
    system ("cls");
    system ("pause");

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Casas{
    string nomeC;
    int indice, energia = 0, atacou = 0, evoluiu = 0;
    
};

struct Cartas{
    string nome, ataque1, fraco, descricao;
    int vida, dano1, suporte = 0, custo1, mover, pegou = 0, evolucao = 0;
    
};

int main(){
    int jogar = 1, tipo, cont=0, bot, i, j, cards, cont1 = 0, cont2 = 0, vidap1 = 500, vidap2 = 500, primeiro = 1, acaba = 0, acabaP = 0, iAux, escolha, pokemon, casa, acabaC = 0, blaine = 0, eMisty, moeda, eErika, pocao, velocidade, velo = 0, acabaT = 0, ataca, mexer, auxInd, auxEne, escolhaM, checar, energy, moverF = 0, energiaF = 0, acabaB = 0, danoAux;
    
    Cartas fogo[14], agua[14], folha[14], p1[14], p2[14], cP1[14], cP2[14];
    
    Casas campo[5][2];
    
    string auxNome;
    
    unsigned seed = time (0);
    srand (seed);
    
    campo[0][0].nomeC = "|"; campo[1][0].nomeC = "-"; campo[2][0].nomeC = "-"; campo[3][0].nomeC = "-"; campo[4][0].nomeC = "|"; campo[0][1].nomeC = "|"; campo[1][1].nomeC = "-"; campo[2][1].nomeC = "-"; campo[3][1].nomeC = "-"; campo[4][1].nomeC = "|";
    
    cout << "\n\n";
    
    // Cartas Fogo
    fogo[0].nome = "Charmander"; fogo[0].ataque1 = "Ember"; fogo[0].fraco = "Agua"; fogo[0].mover = 1; fogo[0].vida = 60; fogo[0].dano1 = 30; fogo[0].custo1 = 1;
    fogo[1].nome = "Charmeleon"; fogo[1].ataque1 = "Fire Claw"; fogo[1].fraco = "Agua"; fogo[1].mover = 2; fogo[1].vida = 90; fogo[1].dano1 = 60; fogo[1].custo1 = 3; fogo[1].evolucao = 1;
    fogo[2].nome = "Charizard"; fogo[2].ataque1 = "Fire Spin"; fogo[2].fraco = "Agua"; fogo[2].mover = 2; fogo[2].vida = 150; fogo[2].dano1 = 100; fogo[2].custo1 = 4; fogo[2].evolucao = 2;
    fogo[3].nome = "Vulpix"; fogo[3].ataque1 = "Flare"; fogo[3].fraco = "Agua"; fogo[3].mover = 1; fogo[3].custo1 = 1; fogo[3].vida = 70; fogo[3].dano1 = 20;
    fogo[4].nome = "Ninetales"; fogo[4].ataque1 = "Flamethrowher"; fogo[4].fraco = "Agua"; fogo[4].mover = 1; fogo[4].vida = 90; fogo[4].dano1 = 90; fogo[4].custo1 = 2; fogo[4].descricao = "Descarte uma Energia deste Pokémon."; fogo[4].evolucao = 3;
    fogo[5].nome = "Ponyta"; fogo[5].ataque1 = "Flare"; fogo[5].fraco = "Agua"; fogo[5].mover = 1; fogo[5].vida = 60; fogo[5].dano1 = 20; fogo[5].custo1 = 1;
    fogo[6].nome = "Rapidash"; fogo[6].ataque1 = "Fire Mane"; fogo[6].fraco = "Agua"; fogo[6].mover = 1; fogo[6].vida = 100; fogo[6].dano1 = 40; fogo[6].custo1 = 1; fogo[6].evolucao = 4;
    fogo[7].nome = "Magmar"; fogo[7].ataque1 = "Magma Punch"; fogo[7].fraco = "Agua"; fogo[7].mover = 2; fogo[7].vida = 80; fogo[7].dano1 = 50; fogo[7].custo1 = 2;
    fogo[8].nome = "Pesquisa de Professor"; fogo[8].descricao = "Puxe 2 cartas"; fogo[8].suporte = 1;
    fogo[9].nome = "Blaine"; fogo[9].descricao = "Durante este turno, os ataques usados por seu Ninetales, Rapidash ou Magmar causam +30 de dano ao Pokémon do seu oponente"; fogo[9].suporte = 1;
    fogo[10].nome = "Blaine"; fogo[10].descricao = "Durante este turno, os ataques usados por seu Ninetales, Rapidash ou Magmar causam +30 de dano ao Pokémon do seu oponente"; fogo[10].suporte = 1;
    fogo[11].nome = "Poção"; fogo[11].descricao = "Cura 20 de HP de 1 de seus Pokemons"; fogo[11].suporte = 1;
    fogo[12].nome = "Poção"; fogo[12].descricao = "Cura 20 de HP de 1 de seus Pokemons"; fogo[12].suporte = 1;
    fogo[13].nome = "Velocidade X"; fogo[13].descricao = "O custo para mover o seu Pokémon é 1 de energia a menos"; fogo[13].suporte = 1;

    //Cartas Agua
    agua[0].nome = "Squirtle"; agua[0].ataque1 = "Water Gun"; agua[0].fraco = "Folha"; agua[0].mover = 1; agua[0].vida = 60; agua[0].dano1 = 20; agua[0].custo1 = 1;
    agua[1].nome = "Wartortle"; agua[1].ataque1 = "Wave Splash"; agua[1].fraco = "Folha"; agua[1].mover = 1; agua[1].vida = 80; agua[1].dano1 = 40; agua[1].custo1 = 2; agua[1].evolucao = 1;
    agua[2].nome = "Blastoise"; agua[2].ataque1 = "Hidro Pump"; agua[2].fraco = "Folha"; agua[2].mover = 3; agua[2].vida = 150; agua[2].dano1 = 100; agua[2].custo1 = 4; agua[2].evolucao = 2;
    agua[3].nome = "Magikarp"; agua[3].ataque1 = "Splash"; agua[3].fraco = "Folha"; agua[3].mover = 1; agua[3].custo1 = 1; agua[3].vida = 30; agua[3].dano1 = 10;
    agua[4].nome = "Gyarados"; agua[4].ataque1 = "Hyper Beam"; agua[4].fraco = "Folha"; agua[4].mover = 4; agua[4].vida = 150; agua[4].dano1 = 100; agua[4].custo1 = 4; agua[4].evolucao = 3;
    agua[5].nome = "Tentacool"; agua[5].ataque1 = "Gentle Slap"; agua[5].fraco = "Folha"; agua[5].mover = 1; agua[5].vida = 60; agua[5].dano1 = 20; agua[5].custo1 = 1;
    agua[6].nome = "Tentacruel"; agua[6].ataque1 = "Wave Splash"; agua[6].fraco = "Folha"; agua[6].mover = 1; agua[6].vida = 100; agua[6].dano1 = 40; agua[6].custo1 = 1; agua[6].evolucao = 4;
    agua[7].nome = "Lapras"; agua[7].ataque1 = "Hidro Pump"; agua[7].fraco = "Folha"; agua[7].mover = 2; agua[7].vida = 100; agua[7].dano1 = 30; agua[7].custo1 = 1;
    agua[8].nome = "Pesquisa de Professor"; agua[8].descricao = "Puxe 2 cartas"; agua[8].suporte = 1;
    agua[9].nome = "Misty"; agua[9].descricao = "Escolha 1 dos seus Pokémon de Água e jogue uma moeda até sair coroa. Para cada cara, coloque uma Energia no Pokemon escolhida"; agua[9].suporte = 1;
    agua[10].nome = "Misty"; agua[10].descricao = "Escolha 1 dos seus Pokémon de Água e jogue uma moeda até sair coroa. Para cada cara, coloque uma Energia no Pokemon escolhida"; agua[10].suporte = 1;
    agua[11].nome = "Poção"; agua[11].descricao = "Cura 20 de HP de 1 de seus Pokemons"; agua[11].suporte = 1;
    agua[12].nome = "Poção"; agua[12].descricao = "Cura 20 de HP de 1 de seus Pokemons"; agua[12].suporte = 1;
    agua[13].nome = "Velocidade X"; agua[13].descricao = "O custo para mover o seu Pokémon é 1 de energia a menos"; agua[13].suporte = 1;
    
    //Cartas Folha
    folha[0].nome = "Bulbasaur"; folha[0].ataque1 = "Vine Whip"; folha[0].fraco = "Fogo"; folha[0].mover = 1; folha[0].vida = 70; folha[0].dano1 = 40; folha[0].custo1 = 2;
    folha[1].nome = "Ivysaur"; folha[1].ataque1 = "Razor Leaf"; folha[1].fraco = "Fogo"; folha[1].mover = 2; folha[1].vida = 90; folha[1].dano1 = 60; folha[1].custo1 = 3; folha[1].evolucao = 1;
    folha[2].nome = "Venusaur"; folha[2].ataque1 = "Mega Drain"; folha[2].fraco = "Fogo"; folha[2].mover = 3; folha[2].vida = 160; folha[2].dano1 = 100; folha[2].custo1 = 4; folha[2].evolucao = 2;
    folha[3].nome = "Paras"; folha[3].ataque1 = "Scratch"; folha[3].fraco = "Fogo"; folha[3].mover = 1; folha[3].custo1 = 2; folha[3].vida = 70; folha[3].dano1 = 30;
    folha[4].nome = "Parasect"; folha[4].ataque1 = "Slash"; folha[4].fraco = "Fogo"; folha[4].mover = 2; folha[4].vida = 120; folha[4].dano1 = 80; folha[4].custo1 = 3; folha[4].evolucao = 3;
    folha[5].nome = "Exeggcute"; folha[5].ataque1 = "Seed Bomb"; folha[5].fraco = "Fogo"; folha[5].mover = 1; folha[5].vida = 50; folha[5].dano1 = 20; folha[5].custo1 = 1;
    folha[6].nome = "Exeggutor"; folha[6].ataque1 = "Stomp"; folha[6].fraco = "Fogo"; folha[6].mover = 3; folha[6].vida = 130; folha[6].dano1 = 60; folha[6].custo1 = 1; folha[6].evolucao = 4;
    folha[7].nome = "Pinsir"; folha[7].ataque1 = "Double horn"; folha[7].fraco = "Fogo"; folha[7].mover = 2; folha[7].vida = 90; folha[7].dano1 = 60; folha[7].custo1 = 2;
    folha[8].nome = "Pesquisa de Professor"; folha[8].descricao = "Puxe 2 cartas"; folha[8].suporte = 1;
    folha[9].nome = "Erika"; folha[9].descricao = "Cure 50 de dano do seu Pokémon"; folha[9].suporte = 1;
    folha[10].nome = "Erika"; folha[10].descricao = "Cure 50 de dano do seu Pokémon"; folha[10].suporte = 1;
    folha[11].nome = "Poção"; folha[11].descricao = "Cura 20 de HP de 1 de seus Pokemons"; folha[11].suporte = 1;
    folha[12].nome = "Poção"; folha[12].descricao = "Cura 20 de HP de 1 de seus Pokemons"; folha[12].suporte = 1;
    folha[13].nome = "Velocidade X"; folha[13].descricao = "O custo para mover o seu Pokémon é 1 de energia a menos"; folha[13].suporte = 1;
    
    
    
    
    
    
    
    

    if(jogar == 1){
        do{
            cout << "\nEscolha o Deck do Jogador1 (1 - Fogo / 2 - Agua / 3 - Planta)\n";
            cin >> tipo;
            
            if((tipo != 1) && (tipo != 2) && (tipo != 3)){
                cout << "\nNúmero invalido, tente novamente\n";
                
            }
            
        }while((tipo != 1) && (tipo != 2) && (tipo != 3));
        
        if (tipo == 1){
            for(i=0;i<14;i++){
                p1[i].nome = fogo[i].nome; p1[i].ataque1 = fogo[i].ataque1; p1[i].fraco = fogo[i].fraco; p1[i].descricao = fogo[i].descricao; p1[i].vida = fogo[i].vida; p1[i].dano1 = fogo[i].dano1; p1[i].suporte = fogo[i].suporte; p1[i].custo1 = fogo[i].custo1; p1[i].mover = fogo[i].mover; p1[i].pegou = fogo[i].pegou; p1[i].evolucao = fogo[i].evolucao;
            }
            
        }else{
            if(tipo == 2){
                for(i=0;i<14;i++){
                    p1[i].nome = agua[i].nome; p1[i].ataque1 = agua[i].ataque1; p1[i].fraco = agua[i].fraco; p1[i].descricao = agua[i].descricao; p1[i].vida = agua[i].vida; p1[i].dano1 = agua[i].dano1; p1[i].suporte = agua[i].suporte; p1[i].custo1 = agua[i].custo1; p1[i].mover = agua[i].mover; p1[i].pegou = agua[i].pegou; p1[i].evolucao = agua[i].evolucao;
                }
                
            }else{
                for(i=0;i<14;i++){
                    p1[i].nome = folha[i].nome; p1[i].ataque1 = folha[i].ataque1; p1[i].fraco = folha[i].fraco; p1[i].descricao = folha[i].descricao; p1[i].vida = folha[i].vida; p1[i].dano1 = folha[i].dano1; p1[i].suporte = folha[i].suporte; p1[i].custo1 = folha[i].custo1; p1[i].mover = folha[i].mover; p1[i].pegou = folha[i].pegou; p1[i].evolucao = folha[i].evolucao;
                }
                
            }
        }
        
        do{
            cout << "\nEscolha o Deck do Jogador2 (1 - Fogo / 2 - Agua / 3 - Planta)\n";
            cin >> bot;
            
            if((bot != 1) && (bot != 2) && (bot != 3)){
                cout << "\nNúmero invalido, tente novamente\n";
                
            }
            
        }while((bot != 1) && (bot != 2) && (bot != 3));

        
        if (bot == 1){
            cout << "\nO seu oponente escolheu o deck de Fogo!\n";
            for(i=0;i<14;i++){
                p2[i].nome = fogo[i].nome; p2[i].ataque1 = fogo[i].ataque1; p2[i].fraco = fogo[i].fraco; p2[i].descricao = fogo[i].descricao; p2[i].vida = fogo[i].vida; p2[i].dano1 = fogo[i].dano1; p2[i].suporte = fogo[i].suporte; p2[i].custo1 = fogo[i].custo1; p2[i].mover = fogo[i].mover; p2[i].pegou = fogo[i].pegou; p2[i].evolucao = fogo[i].evolucao;
            }
            
        }else{
            if(bot == 2){
                cout << "\nO seu oponente escolheu o deck de Agua!\n";
                for(i=0;i<14;i++){
                    p2[i].nome = agua[i].nome; p2[i].ataque1 = agua[i].ataque1; p2[i].fraco = agua[i].fraco; p2[i].descricao = agua[i].descricao; p2[i].vida = agua[i].vida; p2[i].dano1 = agua[i].dano1; p2[i].suporte = agua[i].suporte; p2[i].custo1 = agua[i].custo1; p2[i].mover = agua[i].mover; p2[i].pegou = agua[i].pegou; p2[i].evolucao = agua[i].evolucao;
                }
                
            }else{
                cout << "\nO seu oponente escolheu o deck de Folha!\n";
                for(i=0;i<14;i++){
                    p2[i].nome = folha[i].nome; p2[i].ataque1 = folha[i].ataque1; p2[i].fraco = folha[i].fraco; p2[i].descricao = folha[i].descricao; p2[i].vida = folha[i].vida; p2[i].dano1 = folha[i].dano1; p2[i].suporte = folha[i].suporte; p2[i].custo1 = folha[i].custo1; p2[i].mover = folha[i].mover; p2[i].pegou = folha[i].pegou; p2[i].evolucao = folha[i].evolucao;
                }
            }
        }
        
        system ("pause");
        system ("cls");
        
        cout << "\nAs cartas foram distribuidas!\n";
        
        for(i=0;i<5;i++){
            cards = 0+rand()%13;
            if(p1[cards].pegou == 1){
                cont1--;
                i--;
            }else{
                cP1[cont1].nome = p1[cards].nome; cP1[cont1].ataque1 = p1[cards].ataque1; cP1[cont1].fraco = p1[cards].fraco; cP1[cont1].descricao = p1[cards].descricao; cP1[cont1].vida = p1[cards].vida; cP1[cont1].dano1 = p1[cards].dano1; cP1[cont1].suporte = p1[cards].suporte; cP1[cont1].custo1 = p1[cards].custo1; cP1[cont1].mover = p1[cards].mover; cP1[cont1].pegou = 1; p1[cards].pegou = 1; cP1[cont1].evolucao = p1[cards].evolucao;
            }
            cont1++;
        }
        
        for(i=0;i<5;i++){
            cards = 0+rand()%13;
            if(p2[cards].pegou == 1){
                cont2--;
                i--;
            }else{
                cP2[cont2].nome = p2[cards].nome; cP2[cont2].ataque1 = p2[cards].ataque1; cP2[cont2].fraco = p2[cards].fraco; cP2[cont2].descricao = p2[cards].descricao; cP2[cont2].vida = p2[cards].vida; cP2[cont2].dano1 = p2[cards].dano1; cP2[cont2].suporte = p2[cards].suporte; cP2[cont2].custo1 = p2[cards].custo1; cP2[cont2].mover = p2[cards].mover; cP2[cont2].pegou = 1; p2[cards].pegou = 1; cP2[cont2].evolucao = p2[cards].evolucao;
            }
            cont2++;
        }
        
        cout << "\nSuas cartas foram as seguintes:\n";
        system ("pause");
        system ("cls");
        
        for(i=0;i<5;i++){
            cout << "\n\n";
            if(cP1[i].suporte == 1){
                cout << "\n" << cP1[i].nome; cout << "\n\n" << cP1[i].descricao;
                system ("pause");
                system ("cls");
                
            }else{
                cout << "\n\n" << cP1[i].nome << "\tHP: " << cP1[i].vida; cout << "\n\n" << cP1[i].ataque1 << "\tDMG: " << cP1[i].dano1 << "\n" << "\nCusto para usar o ataque:\t" << cP1[i].custo1; cout << "\nFraqueza: " << cP1[i].fraco; cout << "\n\nEnergia para mover: " << cP1[i].mover;
                system ("pause");
                system ("cls");
                
            }
            
        }
        
        cout << "\n\n\nAs cartas do seu oponente foram:\n";
        system ("pause");
        system ("cls");
        
        for(i=0;i<5;i++){
            cout << "\n\n";
            if(cP2[i].suporte == 1){
                cout << "\n" << cP2[i].nome; cout << "\n\n" << cP2[i].descricao;
                system ("pause");
                system ("cls");
                
            }else{
                cout << "\n\n" << cP2[i].nome << "\tHP: " << cP2[i].vida; cout << "\n\n" << cP2[i].ataque1 << "\tDMG: " << cP2[i].dano1 << "\n" << "\nCusto para usar o ataque:\t" << cP2[i].custo1; cout << "\nFraqueza: " << cP2[i].fraco; cout << "\n\nEnergia para mover: " << cP2[i].mover;
                system ("pause");
                system ("cls");
                
            }
            
        }
        while (((vidap1>0) && (vidap2>0)) && (acabaB == 0)){

            
            if(primeiro == 0){
                while((acaba == 0) && (cont1 <=13)){
                    if(cont1 >= 13){
                        cout << "\nVoce ja pegou todas as cartas do seu baralho\n";
                        acaba = 1;
                        
                        
                    }else{
                        cards = 0+rand()%13;
                        if(p1[cards].pegou == 0){
                            cP1[cont1].nome = p1[cards].nome; cP1[cont1].ataque1 = p1[cards].ataque1; cP1[cont1].fraco = p1[cards].fraco; cP1[cont1].descricao = p1[cards].descricao; cP1[cont1].vida = p1[cards].vida; cP1[cont1].dano1 = p1[cards].dano1; cP1[cont1].suporte = p1[cards].suporte; cP1[cont1].custo1 = p1[cards].custo1; cP1[cont1].mover = p1[cards].mover; cP1[cont1].pegou = 1; p1[cards].pegou = 1; cP1[cont1].evolucao = p1[cards].evolucao;
                            acaba = 1;
                            
                            if(cP1[cont1].suporte == 1){
                                cout << "\nVoce Puxou uma carta e pegou...:\n" << cP1[cont1].nome; cout << "\n\n" << cP1[cont1].descricao;
                                system ("pause");
                                system ("cls");
                                cont1++;
                                
                            }else{
                                cout << "\nVoce puxou uma carta e pegou...:\n\n" << cP1[cont1].nome << "\tHP: " << cP1[cont1].vida; cout << "\n\n" << cP1[cont1].ataque1 << "\tDMG: " << cP1[cont1].dano1 << "\n" << "\nCusto para usar o ataque:\t" << cP1[cont1].custo1; cout << "\nFraquesa: " << cP1[cont1].fraco; cout << "\n\nEnergia para mover: " << cP1[cont1].mover;
                                system ("pause");
                                system ("cls");
                                cont1++;
                                
                            }
                        }
                    }
                    
                }
            }
            do{
                do{
                	cout << "\n\t\tCampo do oponente / HP: " << vidap2 << "\n";
                    for(i=0;i<2;i++){
                        cout << "\n";
                        for(j=0;j<5;j++){
                            cout << "\t" << campo[j][i].nomeC;
                        }
                    }
                    
                    cout << "\n\n\t\tSeu campo / HP: " << vidap1;
                    cout << "\nTurno do Jogador1!\n";
                    if(energiaF == 0){
                        cout << "\nVoce tem uma energia para usar!\n";
                        
                    }
                    cout << "\nDigite o que voce deseja fazer:\n1 - Colocar / usar carta\n2 - Atacar\n3 - Mover carta\n4 - Checar carta\n5 - Colocar energia\n6 - Terminar turno\n";
                    cin >> escolha;
                    
                    if((escolha <= 0) || (escolha >= 7)){
                        cout << "\nFuncao invalida. Tente novamente\n";
						
                    	
                    }
                    
                }while ((escolha <= 0) || (escolha >= 7));
                
                
                getchar();
                
                if(escolha == 1){
                    cout << "\nVoce tem as seguintes cartas em sua mao:\n";
                    
                    for(i=0;i<14;i++){
                        if(cP1[i].nome.empty() == true){
                            
                        }else{
                            if(cP1[i].nome == "-"){
                                
                            }else{
                                cout << i + 1 << ". " << cP1[i].nome << "\n";
                                
                            }
                        }
                        
                    }
                    
                    do{
                        cout << "\nDigite o numero da carta que deseja colocar / usar\n";
                        cin >> pokemon;
                        
                        pokemon--;
                        
                        if((pokemon <= -1) || (pokemon >= cont1)){
                            cout << "\nNumero invalido, tente novamente\n";
                            
                        }else{
                            if(cP1[pokemon].nome == "-"){
                                cout << "\nCarta já usada\n";
                                
                            }
                        }
                        
                    }while(((pokemon <= -1) || (pokemon >= cont1)) || (cP1[pokemon].nome == "-"));
                    
                    
                    for(i=0;i<14;i++){
                        if((cP1[pokemon].nome == p1[i].nome) && (acabaP == 0)){
                            iAux = i;
                            acabaP = 1;
                        }
                    }
                    
                    if(p1[iAux].suporte == 0){
                        if ( ((p1[iAux].evolucao == 1) && (p1[iAux - 1].evolucao == 0) && ((campo[1][1].nomeC == p1[iAux - 1].nome) || (campo[2][1].nomeC == p1[iAux - 1].nome) || (campo[3][1].nomeC == p1[iAux - 1].nome))) || ((p1[iAux].evolucao == 2) && (p1[iAux - 1].evolucao == 1) && ((campo[1][1].nomeC == p1[iAux - 1].nome) || (campo[2][1].nomeC == p1[iAux - 1].nome) || (campo[3][1].nomeC == p1[iAux - 1].nome))) || ((p1[iAux].evolucao == 4) && (p1[iAux - 1].evolucao == 0) && ((campo[1][1].nomeC == p1[iAux - 1].nome) || (campo[2][1].nomeC == p1[iAux - 1].nome) || (campo[3][1].nomeC == p1[iAux - 1].nome))) || ((p1[iAux].evolucao == 6) && (p1[iAux - 1].evolucao == 0) && ((campo[1][1].nomeC == p1[iAux - 1].nome) || (campo[2][1].nomeC == p1[iAux - 1].nome) || (campo[3][1].nomeC == p1[iAux - 1].nome))) || ((p1[iAux].evolucao == 3) && (p1[iAux - 1].evolucao == 0) && ((campo[1][1].nomeC == p1[iAux - 1].nome) || (campo[2][1].nomeC == p1[iAux - 1].nome) || (campo[3][1].nomeC == p1[iAux - 1].nome))) ) {
                            for(i=1;i<4;i++){
                                if(p1[iAux - 1].nome == campo[i][1].nomeC){
                                    if(campo[i][1].evoluiu == 1){
                                        cout << "\nEste Pokemon ja evoluiu neste turno\n";
                                        system ("pause");
                                        system ("cls");
                                        
                                    }else{
                                        campo[i][1].nomeC = p1[iAux].nome;
                                        campo[i][1].indice = iAux;
                                        cout << "\nVoce evoluiu sua carta!\n";
                                        campo[i][1].evoluiu = 1;
                                        cP1[pokemon].nome = "-";
                                        system ("pause");
                                        system ("cls");
                                        
                                    }
                                    
                                }
                            }
                            
                        }else{
                            if((campo[1][1].nomeC != "-") && (campo[2][1].nomeC != "-") && (campo[3][1].nomeC != "-")){
                                cout << "\nNão ha casas disponiveis\n";
                                system ("pause");
                                system ("cls");
                                
                            }else{
                                if(p1[iAux].evolucao != 0){
                                    cout << "\nA inevolução desta carta nao esta em campo\n";
                                    system ("pause");
                                    system ("cls");
                                    
                                }else{
                                    cout << "\nEscolha em qual casa do seu campo voce vai querer jogar a carta!\nCasas disponiveis:\n";
                                    
                                    for(i=1;i<4;i++){
                                        if(campo[i][1].nomeC == "-"){
                                            cout << "\nA casa " << i << " do seu campo esta disponivel\n";
                                            
                                        }
                                    }
                                    
                                    do{
                                        cin >> casa;
                                        
                                        if((casa == 1) && (campo[1][1].nomeC == "-")){
                                            acabaC = 1;
                                            campo[1][1].nomeC = p1[iAux].nome;
                                            campo[1][1].indice = iAux;
                                            
                                        }else{
                                            if((casa == 2) && (campo[2][1].nomeC == "-")){
                                                acabaC = 1;
                                                campo[2][1].nomeC = p1[iAux].nome;
                                                campo[2][1].indice = iAux;
                                                
                                            }else{
                                                if((casa == 3) && (campo[3][1].nomeC == "-")){
                                                    acabaC = 1;
                                                    campo[3][1].nomeC = p1[iAux].nome;
                                                    campo[3][1].indice = iAux;
                                                    
                                                }else{
                                                    cout << "\nA casa escolhida nao esta disponível. Tente novamente\n";

                                                    
                                                }
                                            }
                                        }
                                        
                                    }while(((casa <= 0) || (casa >= 4)) || (acabaC == 0));
                                    
                                    cP1[pokemon].nome = "-";
                                    system ("pause");
                                    system ("cls");
                                    
                                }
                            }
                        }
                    }else{
                        if(iAux == 8){
                            cout << "\nVoce usou a carta 'Pesquisa de Professor' e ganhou 2 cartas!\n";
                            
                            for(i=0;i<2;i++){
                                if(cont1 >= 13){
                                    cout << "\nNao ha mais cartas em seu baralho\n";
                                    system ("pause");
                                    system ("cls");
                                    
                                }else{
                                	system ("pause");
                                    system ("cls");
                                    cards = 0+rand()%13;
                                    if(p1[cards].pegou == 0){
                                        cP1[cont1].nome = p1[cards].nome; cP1[cont1].ataque1 = p1[cards].ataque1; cP1[cont1].fraco = p1[cards].fraco; cP1[cont1].descricao = p1[cards].descricao; cP1[cont1].vida = p1[cards].vida; cP1[cont1].dano1 = p1[cards].dano1; cP1[cont1].suporte = p1[cards].suporte; cP1[cont1].custo1 = p1[cards].custo1; cP1[cont1].mover = p1[cards].mover; cP1[cont1].pegou = 1; p1[cards].pegou = 1; cP1[cont1].evolucao = p1[cards].evolucao;
                                        if(cP1[cont1].suporte == 1){
                                            cout << "\nVoce Puxou uma carta e pegou...:\n" << cP1[cont1].nome; cout << "\n\n" << cP1[cont1].descricao;
                                            system ("pause");
                                            system ("cls");
                                            
                                        }else{
                                            cout << "\nVoce puxou uma carta e pegou...:\n\n" << cP1[cont1].nome << "\tHP: " << cP1[cont1].vida; cout << "\n\n" << cP1[cont1].ataque1 << "\tDMG: " << cP1[cont1].dano1 << "\n" << "\nCusto para usar o ataque:\t" << cP1[cont1].custo1; cout << "\nFraquesa: " << cP1[cont1].fraco; cout << "\n\nEnergia para mover: " << cP1[cont1].mover;
                                            system ("pause");
                                            system ("cls");
                                            
                                        }
                                    }else{
                                        i--;
                                        cont1--;
                                    }
                                    cont1++;
                                }
                            }
                            
                            cP1[pokemon].nome = "-";
                            
                        }else{
                            if((iAux == 9) || (iAux == 10)){
                                if(p1[iAux].nome == "Blaine"){
                                    cout << "\nVoce usou a carta 'Blaine'! Por este turno, Ninetales, Magmar e Rapidash vão dar 30 de dano a mais!\n";
                                    blaine = 1;
                                    cP1[pokemon].nome = "-";
                                    system ("pause");
                                    system ("cls");
                                    
                                }else{
                                    if(p1[iAux].nome == "Misty"){
                                        cout << "\nEscolha o Pokemon que deseja usar esta carta:\n";
                                        
                                        if((campo[1][1].nomeC == "-") && (campo[2][1].nomeC == "-") && (campo[3][1].nomeC == "-")){
                                            cout << "\nVoce nao tem cartas em campo\n";
                                            
                                        }else{
                                            for(i=1;i<4;i++){
                                                if(campo[i][1].nomeC == "-"){
                                                    
                                                }else{
                                                    cout << i << ". " << campo[i][1].nomeC << "\n";
                                                }
                                                
                                            }
                                            
                                            do{
                                                cin >> eMisty;
                                                
                                                if((eMisty <= 0) || (eMisty >=4)){
                                                    cout << "\nNumero invalido. Tente novamente\n";
                                                    
                                                }else{
                                                    if(campo[eMisty][1].nomeC == "-"){
                                                        cout << "\nEsta casa esta vazia. Tente novamente\n";
                                                        
                                                    }
                                                }
                                                
                                            }while((eMisty <= 0) || (eMisty >=4) || (campo[eMisty][1].nomeC == "-"));
                                            
                                            cout << "\nAgora uma moeda vai ser jogada ate sair coroa. Para cada cara, coloque uma Energia sera colocada no pokemon escolhido.!\n";
                                            system ("pause");
                                            system ("cls");
                                            
                                            do{
                                                moeda = 1+rand()%2;
                                                
                                                if(moeda == 1){
                                                    cout << "\nCaiu cara!\n";
                                                    campo[eMisty][1].energia++;
                                                    
                                                }else{
                                                    cout << "\nCaiu coroa\n";
                                                    
                                                }
                                            }while(moeda == 1);
                                            
                                            cout << "\nA energia do seu " << campo[eMisty][1].nomeC << " agora é de " << campo[eMisty][1].energia;
                                            cP1[pokemon].nome = "-";
                                            
                                            system ("pause");
                                            system ("cls");
                                            
                                        }
                                    }else{
                                        if(p1[iAux].nome == "Erika"){
                                            cout << "\nEscolha o Pokemon que deseja usar esta carta:\n";
                                            
                                            if((campo[1][1].nomeC == "-") && (campo[2][1].nomeC == "-") && (campo[3][1].nomeC == "-")){
                                                cout << "\nVoce nao tem cartas em campo\n";
                                                
                                            }else{
                                                for(i=1;i<4;i++){
                                                    if(campo[i][1].nomeC == "-"){
                                                        
                                                    }else{
                                                        cout << i << ". " << campo[i][1].nomeC << "\n";
                                                    }
                                                    
                                                }
                                                
                                                do{
                                                    cin >> eErika;
                                                    
                                                    if((eErika <= 0) || (eErika >=4)){
                                                        cout << "\nNumero invalido. Tente novamente\n";
                                                        
                                                    }else{
                                                        if(campo[eErika][1].nomeC == "-"){
                                                            cout << "\nEsta casa esta vazia. Tente novamente\n";
                                                            
                                                        }
                                                    }
                                                }while((eErika <= 0) || (eErika >=4) || (campo[eErika][1].nomeC == "-"));
                                                

                                                cout << "\n" << campo[eErika][1].nomeC << " recuperou 50 de HP!\n";
                                                
                                                for(i=0;i<14;i++){
                                                    if(campo[eErika][1].nomeC == p1[i].nome){
                                                        p1[i].vida = p1[i].vida + 50;
                                                        
                                                    }
                                                }
                                                
                                                cP1[pokemon].nome = "-";
                                                
                                                system ("pause");
                                                system ("cls");
                                                
                                            }
                                        }
                                    }
                                }
                                
                            }else{
                                if((iAux == 11) || (iAux == 12)){
                                    cout << "\nEscolha o Pokemon que voce deseja usar esta carta:\n";
                                    
                                    if((campo[1][1].nomeC == "-") && (campo[2][1].nomeC == "-") && (campo[3][1].nomeC == "-")){
                                        cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                        
                                    }else{
                                        for(i=1;i<4;i++){
                                            if(campo[i][1].nomeC == "-"){
                                                
                                            }else{
                                                cout << i << ". " << campo[i][1].nomeC << "\n";
                                                
                                            }
                                          
                                        }
                                        
                                        do{
                                            cin >> pocao;
                                            
                                            if((pocao <= 0) || (pocao >=4)){
                                                cout << "\nNumero invalido. Tente novamente\n";
                                                
                                            }else{
                                                if(campo[pocao][1].nomeC == "-"){
                                                    cout << "\nCasa vazia. Tente novamente\n";
                                                    
                                                }
                                            }
                                            
                                        }while((pocao <= 0) || (pocao >=4) || (campo[pocao][1].nomeC == "-"));
                                        
                                        cout << "\n" << campo[pocao][1].nomeC << "recuperou 20 de HP!\n";
                                        
                                        for(i=0;i<14;i++){
                                            if(campo[pocao][1].nomeC == p1[i].nome){
                                                p1[i].vida += 20;
                                                
                                            }
                                        }
                                        
                                        cP1[pokemon].nome = "-";
                                        system ("pause");
                                        system ("cls");
                                        
                                    }
                                    
                                }else{
                                    if(iAux == 13){
                                        cout << "\nEscolha o Pokemon que voce deseja usar esta carta:\n";
                                        
                                        if((campo[1][1].nomeC == "-") && (campo[2][1].nomeC == "-") && (campo[3][1].nomeC == "-")){
                                            cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                            
                                        }else{
                                            for(i=1;i<4;i++){
                                                if(campo[i][1].nomeC == "-"){
                                                    
                                                }else{
                                                    cout << i << ". " << campo[i][1].nomeC << "\n";
                                                    
                                                }
                                              
                                            }
                                            
                                            do{
                                                cin >> velocidade;
                                                
                                                if((velocidade <= 0) || (velocidade >=4)){
                                                    cout << "\nNumero invalido. Tente novamente\n";
                                                    
                                                }else{
                                                    if(campo[velocidade][1].nomeC == "-"){
                                                        cout << "\nCasa vazia. Tente novamente\n";
                                                        
                                                    }
                                                }
                                                
                                            }while((velocidade <= 0) || (velocidade >=4) || (campo[velocidade][1].nomeC == "-"));
                                            
                                            cout << "\n" << campo[velocidade][1].nomeC << " precidara de -1 energia para se mover\n";
                                            
                                            for(i=0;i<14;i++){
                                                if(campo[velocidade][1].nomeC == p1[i].nome){
                                                    p1[i].mover = p1[i].mover - 1;
                                                }
                                            }
                                            
                                            cP1[pokemon].nome = "-";
                                            
                                            system ("pause");
                                            system ("cls");
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                    acabaP = 0; acabaC = 0;
                    
                }else{
                    if(escolha == 2){
                        if(primeiro == 1){
                            cout << "\nVoce nao pode atacar no primeiro turno\n";
                            system ("pause");
                            system ("cls");
                            
                        }else{
                            cout << "\nEscolha o Pokemon que voce quer usar para atacar\n";
                            
                            if((campo[1][1].nomeC == "-") && (campo[2][1].nomeC == "-") && (campo[3][1].nomeC == "-")){
                                cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                
                            }else{
                                for(i=1;i<4;i++){
                                    if(campo[i][1].nomeC == "-"){
                                        
                                    }else{
                                        cout << i << ". " << campo[i][1].nomeC << "\n";
                                    }
                                    
                                }
                                
                                do{
                                    cin >> ataca;
                                    
                                    if((ataca <=0) || (ataca >=4)){
                                        cout << "\nCasa invalida. Tente novamente\n";
                                        
                                    }else{
                                        if(campo[ataca][1].nomeC == "-"){
                                            cout << "\nCasa vazia. Tente novamente\n";
                                            
                                        }else{
                                            if(campo[ataca][1].atacou == 1){
                                                cout << "\nEste Pokemon ja atacou neste round\n";
                                            }
                                        }
                                    }
                                }while((ataca <= 0) || (ataca >= 4) || (campo[ataca][1].nomeC == "-") || (campo[ataca][1].atacou == 1));
                                
                                if(campo[ataca][1].energia < p1[campo[ataca][1].indice].custo1){
                                    cout << "\nSeu Pokemon nao tem energia suficiente para atacar\n";
                                    
                                }else{
                                    campo[ataca][1].atacou = 1;
                                    if(campo[ataca][0].nomeC == "-"){
                                        for(i=0;i<14;i++){
                                            if(campo[ataca][1].nomeC == p1[i].nome){
                                                danoAux = p1[i].dano1;
                                                if(blaine == 1){
                                                    if((p1[i].nome == "Ninetales") || (p1[i].nome == "Magmar") || (p1[i].nome == "Rapidash")){
                                                        p1[i].dano1 = p1[i].dano1 + 30;
                                                        
                                                    }
                                                }
                                                vidap2 = vidap2 - p1[i].dano1;
                                                cout << "\nSeu " << p1[i].nome << " deu " << p1[i].dano1 << " no Player2, ficando com " << vidap2 << "\n";
                                                p1[i].dano1 = danoAux;
                                                
                                            }
                                        }
                                    }else{
                                        for(i=0;i<14;i++){
                                            if(campo[ataca][1].nomeC == p1[i].nome){
                                                for(j=0;j<14;j++){
                                                    if(campo[ataca][0].nomeC == p2[j].nome){
                                                        danoAux = p1[i].dano1;
                                                        if((p1[i].fraco == "Agua") && (p2[j].fraco == "Fogo")){
                                                            if(blaine == 1){
                                                                if((p1[i].nome == "Ninetales") || (p1[i].nome == "Magmar") || (p1[i].nome == "Rapidash")){
                                                                    p1[i].dano1 = p1[i].dano1 + 30;
                                                                }
                                                            }
                                                            p1[i].dano1 = p1[i].dano1 * 2;
                                                            p2[j].vida = p2[j].vida - p1[i].dano1;
                                                            cout << "\nSeu ataque foi super efetivo!\n";
                                                            cout << "\nSeu " << p1[i].nome << " deu " << p1[i].dano1 << " no " << p2[j].nome << " do Player2, deixando ele com " << p2[j].vida << " de HP\n";
                                                            p1[i].dano1 = danoAux;
                                                            system ("pause");
                                                            system ("cls");
                                                            
                                                        }else{
                                                            if((p1[i].fraco == "Folha") && (p2[j].fraco == "Agua")){
                                                                if(blaine == 1){
                                                                    if((p1[i].nome == "Ninetales") || (p1[i].nome == "Magmar") || (p1[i].nome == "Rapidash")){
                                                                        p1[i].dano1 = p1[i].dano1 + 30;
                                                                        
                                                                    }
                                                                }
                                                                p1[i].dano1 = p1[i].dano1 * 2;
                                                                p2[j].vida = p2[j].vida - p1[i].dano1;
                                                                cout << "\nSeu ataque foi super efetivo!\n";
                                                                cout << "\nSeu " << p1[i].nome << " deu " << p1[i].dano1 << " no " << p2[j].nome << " do Player2, deixando ele com " << p2[j].vida << " de HP\n";
                                                                p1[i].dano1 = danoAux;
                                                                system ("pause");
                                                                system ("cls");
                                                                
                                                            }else{
                                                                if((p1[i].fraco == "Fogo") && (p2[j].fraco == "Folha")){
                                                                    if(blaine == 1){
                                                                        if((p1[i].nome == "Ninetales") || (p1[i].nome == "Magmar") || (p1[i].nome == "Rapidash")){
                                                                           p1[i].dano1 = p1[i].dano1 + 30;
                                                                           
                                                                        }
                                                                    }
                                                                    p1[i].dano1 = p1[i].dano1 * 2;
                                                                    p2[j].vida = p2[j].vida - p1[i].dano1;
                                                                    cout << "\nSeu ataque foi super efetivo!\n";
                                                                    cout << "\nSeu " << p1[i].nome << " deu " << p1[i].dano1 << " no " << p2[j].nome << " do Player2, deixando ele com " << p2[j].vida << " de HP\n";
                                                                    p1[i].dano1 = danoAux;
                                                                    system ("pause");
                                                                    system ("cls");
                                                                    
                                                                }else{
                                                                    if(blaine == 1){
                                                                        if((p1[i].nome == "Ninetales") || (p1[i].nome == "Magmar") || (p1[i].nome == "Rapidash")){
                                                                            p1[i].dano1 = p1[i].dano1 + 30;
                                                                            
                                                                        }
                                                                    }
                                                                    p2[j].vida = p2[j].vida - p1[i].dano1;
                                                                    cout << "\nSeu " << p1[i].nome << " deu " << p1[i].dano1 << " no " << p2[j].nome << " do Player2, deixando ele com " << p2[j].vida << " de HP\n";
                                                                    p1[i].dano1 = danoAux;
                                                                    system ("pause");
                                                                    system ("cls");
                                                                    
                                                                }
                                                            }
                                                        }
                                                        
                                                        if(p2[j].vida <= 0){
                                                            cout << "\nO " << p2[j].nome << " do Player2 desmaiou!\n";
                                                            campo[ataca][0].nomeC = "-"; campo[ataca][0].energia = 0;
                                                            
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
                        if(escolha == 3){
                            if(moverF == 1){
                                cout << "\nVoce ja moveu uma carta nesse round\n";
                                system ("pause");
                                system ("cls");
                                
                            }else{
                                cout << "\nEscolha o Pokemon que voce quer mover de posição\n";
                                
                                if((campo[1][1].nomeC == "-") && (campo[2][1].nomeC == "-") && (campo[3][1].nomeC == "-")){
                                    cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                    
                                }else{
                                    for(i=1;i<4;i++){
                                        if(campo[i][1].nomeC == "-"){
                                            
                                        }else{
                                            cout << i << ". " << campo[i][1].nomeC << "\n";
                                        }
                                        
                                    }
                                    
                                    do{
                                        cin >> mexer;
                                        
                                        if((mexer <= 0) || (mexer >= 4)){
                                            cout << "\nCasa invalida. Tente novamente\n";
                                            
                                        }else{
                                            if(campo[mexer][1].nomeC == "-"){
                                                cout << "\nCasa vazia. Tente novamente\n";
                                                
                                            }
                                        }
                                        
                                    }while ((mexer <= 0) || (mexer >=4) || (campo[mexer][1].nomeC == "-"));
                                    
                                    if(campo[mexer][1].energia < p1[campo[mexer][1].indice].mover){
                                        cout << "\nEnergia insuficiente\n";
                                        
                                    }else{
                                        if(mexer == 1){
                                            moverF = 1;
                                            auxNome = campo[1][1].nomeC; campo[1][1].nomeC = campo[2][1].nomeC; campo[2][1].nomeC = auxNome;
                                            auxInd = campo[1][1].indice; campo[1][1].indice = campo[2][1].indice; campo[2][1].indice = auxInd;
                                            auxEne = campo[1][1].energia; campo[1][1].energia = campo[2][1].energia; campo[2][1].energia = auxEne;
                                            
                                        }else{
                                            if(mexer == 2){
                                                do{
                                                    system ("pause");
                                                    system ("cls");
                                                    
                                                    cout << "\n\t\tCampo do oponente / HP: " << vidap2 << "\n";
                                                    for(i=0;i<2;i++){
                                                        cout << "\n";
                                                        for(j=0;j<5;j++){
                                                        cout << "\t" << campo[j][i].nomeC;
                                                        }
                                                    }
                                                    cout << "\n\n\t\tSeu campo / HP: " << vidap1;
                                                    
                                                    cout << "\nMover para esquerda ou para Direita? (1 - Esquerda / 2 - Direita)\n";
                                                    cin >> escolhaM;
                                                    
                                                    if((escolhaM <=0) || (escolhaM >= 3)){
                                                        cout << "\nNumero Inavlido. Tente novamente\n";
                                                        
                                                    }
                                                }while ((escolhaM <=0) || (escolhaM >= 3));
                                                
                                                if(escolhaM == 1){
                                                    auxNome = campo[2][1].nomeC; campo[2][1].nomeC = campo[1][1].nomeC; campo[1][1].nomeC = auxNome;
                                                    auxInd = campo[2][1].indice; campo[2][1].indice = campo[1][1].indice; campo[1][1].indice = auxInd;
                                                    auxEne = campo[2][1].energia; campo[2][1].energia = campo[1][1].energia; campo[1][1].energia = auxEne;
                                                    
                                                }else{
                                                    auxNome = campo[2][1].nomeC; campo[2][1].nomeC = campo[3][1].nomeC; campo[3][1].nomeC = auxNome;
                                                    auxInd = campo[2][1].indice; campo[2][1].indice = campo[3][1].indice; campo[3][1].indice = auxInd;
                                                    auxEne = campo[2][1].energia; campo[2][1].energia = campo[3][1].energia; campo[3][1].energia = auxEne;
                                                    
                                                }
                                            }else{
                                                auxNome = campo[3][1].nomeC; campo[3][1].nomeC = campo[2][1].nomeC; campo[2][1].nomeC = auxNome;
                                                auxInd = campo[3][1].indice; campo[3][1].indice = campo[2][1].indice; campo[2][1].indice = auxInd;
                                                auxEne = campo[3][1].energia; campo[3][1].energia = campo[2][1].energia; campo[2][1].energia = auxEne;
                                                
                                            }
                                        }
                                        
                                    }
                                }
                            }
                            
                            system ("pause");
                            system ("cls");
                            
                            
                        }else{
                            if(escolha == 4){
                                cout << "\nEscolha qual carta voce quer checar:\n";
                                
                                if((campo[1][1].nomeC == "-") && (campo[2][1].nomeC == "-") && (campo[3][1].nomeC == "-")){
                                    cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                    system ("pause");
                                    system ("cls");
                                    
                                }else{
                                    for(i=1;i<4;i++){
                                        if(campo[i][1].nomeC == "-"){
                                            
                                        }else{
                                            cout << i << ". " << campo[i][1].nomeC << "\n";
                                        }
                                        
                                    }
                                    
                                    do{
                                        cin >> checar;
                                        
                                        if((checar <= 0) || (checar >=4)){
                                            cout << "\nCasa invalida. Tente novamente\n";
                                            
                                        }else{
                                            if(campo[checar][1].nomeC == "-"){
                                                cout << "\nCasa vazia. Tente novamente\n";
                                                
                                            }
                                        }
                                        
                                    }while ((checar <= 0) || (checar >=4) || (campo[checar][1].nomeC == "-"));
                                    
                                    for(i=0;i<14;i++){
                                        if(campo[checar][1].nomeC == p1[i].nome){
                                            cout << "\n\n" << p1[i].nome << "\tHP: " << p1[i].vida; cout << "\n\n" << p1[i].ataque1 << "\tDMG: " << p1[i].dano1 << "\n" << "\nCusto para usar ataque:\t" << p1[i].custo1; cout << "\nFraqueza: " << p1[i].fraco; cout << "\n\nEnergia para mover: " << p1[i].mover; cout << "\nEnergia presente na carta: " << campo[checar][1].energia << "\n\n";
                                            system ("pause");
                                            system ("cls");
                                            
                                        }
                                    }
                                    
                                }

                                
                                
                                
                                
                            }else{
                                if(escolha == 5){
                                    if(energiaF == 1){
                                        cout << "\nVoce ja adicionou uma energia neste turno\n";
                                        system ("pause");
                                        system ("cls");
                                        
                                    }else{
                                        energiaF = 1;
                                        cout << "\nEscolha qual carta voce quer adicionar a energia:\n";
                                        
                                        if((campo[1][1].nomeC == "-") && (campo[2][1].nomeC == "-") && (campo[3][1].nomeC == "-")){
                                            cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                            
                                        }else{
                                            for(i=1;i<4;i++){
                                                if(campo[i][1].nomeC == "-"){
                                                    
                                                }else{
                                                    cout << i << ". " << campo[i][1].nomeC << "\n";
                                                }
                                                
                                            }
                                            do{
                                                cin >> energy;
                                                
                                                if((energy <= 0) || (energy >=4)){
                                                    cout << "\nCasa invalida. Tente novamente\n";
                                                    
                                                }else{
                                                    if(campo[energy][1].nomeC == "-"){
                                                        cout << "\nCasa vazia. Tente novamente\n";
                                                        
                                                    }
                                                }
                                                
                                            }while ((energy <= 0) || (energy >=4) || (campo[energy][1].nomeC == "-"));
                                            
                                            cout << "\nEnergia adicionada com sucesso!\n";
                                            
                                            campo[energy][1].energia = campo[energy][1].energia + 1;
                                            
                                            cout << "\nSeu " << campo[energy][1].nomeC << " agora tem " << campo[energy][1].energia << " de energia!\n";
                                            system ("pause");
                                            system ("cls");
                                            
                                        }
                                    }
                                    

                                    
                                }else{
                                    acabaT = 1;
                                }
                            }
                        }
                    }
                }
            }while ((acabaT == 0) && (vidap1 > 0) && (vidap2 > 0));
            
            system ("pause");
        	system ("cls");
            
            primeiro = 0; acaba = 0; energiaF = 0; acabaT = 0; blaine = 0; moverF = 0; acabaP = 0; campo[1][1].atacou = 0; campo[2][1].atacou = 0; campo[3][1].atacou = 0; campo[1][1].evoluiu = 0; campo[2][1].evoluiu = 0; campo[3][1].evoluiu = 0;
            
            if(velo == 1){
                velo = 0;
                for(i=0;i<14;i++){
                    if(campo[velocidade][1].nomeC == p1[i].nome){
                        p1[i].mover = p1[i].mover + 1;
                    }
                }
                
            }
            
            if(vidap1 <= 0){
                cout << "\nO Jogador2 ganhou a Batalha!\n";
                acabaB = 1;
                
            }else{
                if(vidap2 <= 0){
                    cout << "\nO Jogador1 ganhou a Batalha\n";
                    acabaB = 1;
                    
                }else{

                    
                    if(primeiro == 0){
                        while((acaba == 0) && (cont2<=13)){
                            if(cont2 >= 13){
                                cout << "\nVoce ja pegou todas as cartas do seu baralho\n";
                                acaba = 1;
                                
                                
                            }else{

                                
                                cards = 0+rand()%13;
                                if(p2[cards].pegou == 0){
                                    cP2[cont2].nome = p2[cards].nome; cP2[cont2].ataque1 = p2[cards].ataque1; cP2[cont2].fraco = p2[cards].fraco; cP2[cont2].descricao = p2[cards].descricao; cP2[cont2].vida = p2[cards].vida; cP2[cont2].dano1 = p2[cards].dano1; cP2[cont2].suporte = p2[cards].suporte; cP2[cont2].custo1 = p2[cards].custo1; cP2[cont2].mover = p2[cards].mover; cP2[cont2].pegou = 1; p2[cards].pegou = 1; cP2[cont2].evolucao = p2[cards].evolucao;
                                    acaba = 1;
                                    
                                    if(cP2[cont2].suporte == 1){
                                        cout << "\nVoce Puxou uma carta e pegou...:\n" << cP2[cont2].nome; cout << "\n\n" << cP2[cont2].descricao;
                                        system ("pause");
                                        system ("cls");
                                        cont2++;
                                        
                                    }else{
                                        cout << "\nVoce puxou uma carta e pegou...:\n\n" << cP2[cont2].nome << "\tHP: " << cP2[cont2].vida; cout << "\n\n" << cP2[cont2].ataque1 << "\tDMG: " << cP2[cont2].dano1 << "\n" << "\nCusto para usar o ataque:\t" << cP2[cont2].custo1; cout << "\nFraquesa: " << cP2[cont2].fraco; cout << "\n\nEnergia para mover: " << cP2[cont2].mover;
                                        system ("pause");
                                        system ("cls");
                                        cont2++;
                                        
                                    }
                                }
                            }
                            
                        }
                    }
                    do{
                        do{
                        	cout << "\n\t\tCampo do oponente / HP: " << vidap2 << "\n";
                    		for(i=0;i<2;i++){
                        		cout << "\n";
                        		for(j=0;j<5;j++){
                        	    	cout << "\t" << campo[j][i].nomeC;
                       	 		}
                    		}
                    		cout << "\n\n\t\tSeu campo / HP: " << vidap1;
                    		
                            cout << "\nTurno do Jogador2!\n";
                            if(energiaF == 0){
                                cout << "\nVoce tem uma energia para usar!\n";
                                
                            }
                            cout << "\nDigite o que voce deseja fazer:\n1 - Colocar / usar carta\n2 - Atacar\n3 - Mover carta\n4 - Checar carta\n5 - Colocar energia\n6 - Terminar turno\n";
                            cin >> escolha;
                            
                            if((escolha <= 0) || (escolha >= 7)){
                                cout << "\nFuncao invalida. Tente novamente\n";
                                
                            }
                            
                        }while ((escolha <= 0) || (escolha >= 7));
                        
                        getchar();
                        
                        if(escolha == 1){
                            cout << "\nVoce tem as seguintes cartas em sua mao:\n";
                            
                            for(i=0;i<14;i++){
                                if(cP2[i].nome.empty() == true){
                                    
                                }else{
                                    if(cP2[i].nome == "-"){
                                        
                                    }else{
                                        cout << i + 1 << ". " << cP2[i].nome << "\n";
                                        
                                    }
                                }
                                
                            }
                            
                            do{
                                cout << "\nDigite o numero da carta que deseja colocar / usar\n";
                                cin >> pokemon;
                                
                                pokemon--;
                                
                                if((pokemon <= -1) || (pokemon >= cont1)){
                                    cout << "\nNumero invalido, tente novamente\n";
                                    
                                }else{
                                    if(cP2[pokemon].nome == "-"){
                                        cout << "\nCarta já usada\n";
                                        
                                    }
                                }
                                
                            }while(((pokemon <= -1) || (pokemon >= cont2)) || (cP2[pokemon].nome == "-"));
                            
                            for(i=0;i<14;i++){
                                if((cP2[pokemon].nome == p2[i].nome) && (acabaP == 0)){
                                    iAux = i;
                                    acabaP = 1;
                                }
                            }
                            
                            if(p2[iAux].suporte == 0){
                                if ( ((p2[iAux].evolucao == 1) && (p2[iAux - 1].evolucao == 0) && ((campo[1][0].nomeC == p2[iAux - 1].nome) || (campo[2][0].nomeC == p2[iAux - 1].nome) || (campo[3][0].nomeC == p2[iAux - 1].nome))) || ((p2[iAux].evolucao == 2) && (p2[iAux - 1].evolucao == 1) && ((campo[1][0].nomeC == p2[iAux - 1].nome) || (campo[2][0].nomeC == p2[iAux - 1].nome) || (campo[3][0].nomeC == p2[iAux - 1].nome))) || ((p2[iAux].evolucao == 4) && (p2[iAux - 1].evolucao == 0) && ((campo[1][0].nomeC == p2[iAux - 1].nome) || (campo[2][0].nomeC == p2[iAux - 1].nome) || (campo[3][0].nomeC == p2[iAux - 1].nome))) || ((p2[iAux].evolucao == 6) && (p2[iAux - 1].evolucao == 0) && ((campo[1][0].nomeC == p2[iAux - 1].nome) || (campo[2][0].nomeC == p2[iAux - 1].nome) || (campo[3][0].nomeC == p2[iAux - 1].nome))) || ((p2[iAux].evolucao == 3) && (p2[iAux - 1].evolucao == 0) && ((campo[1][0].nomeC == p2[iAux - 1].nome) || (campo[2][0].nomeC == p2[iAux - 1].nome) || (campo[3][0].nomeC == p2[iAux - 1].nome))) ) {
                                    for(i=1;i<4;i++){
                                        if(p2[iAux - 1].nome == campo[i][0].nomeC){
                                            if(campo[i][0].evoluiu == 1){
                                                cout << "\nEste Pokemon ja evoluiu neste round\n";
                                                system ("pause");
                                                system ("cls");
                                                
                                            }else{
                                                campo[i][0].nomeC = p2[iAux].nome;
                                                campo[i][0].indice = iAux;
                                                cout << "\nVoce evoluiu sua carta!\n";
                                                campo[i][0].evoluiu = 1;
                                                cP2[pokemon].nome = "-";
                                                system ("pause");
                                                system ("cls");
                                                
                                            }
                                            
                                        }
                                    }
                                    
                                }else{
                                    if((campo[1][0].nomeC != "-") && (campo[2][0].nomeC != "-") && (campo[3][0].nomeC != "-")){
                                        cout << "\nNão ha casas disponiveis\n";
                                        system ("pause");
                                        system ("cls");
                                        
                                    }else{
                                        if(p2[iAux].evolucao != 0){
                                            cout << "\nA inevolução desta carta nao esta em campo\n";
                                            system ("pause");
                                            system ("cls");
                                            
                                        }else{
                                            cout << "\nEscolha em qual casa do seu campo voce vai querer jogar a carta!\nCasas disponiveis:\n";
                                            
                                            for(i=1;i<4;i++){
                                                if(campo[i][0].nomeC == "-"){
                                                    cout << "\nA casa " << i << " do seu campo esta disponivel\n";
                                                    
                                                }
                                            }
                                            
                                            do{
                                                cin >> casa;
                                                
                                                if((casa == 1) && (campo[1][0].nomeC == "-")){
                                                    acabaC = 1;
                                                    campo[1][0].nomeC = p2[iAux].nome;
                                                    campo[1][0].indice = iAux;
                                                    
                                                }else{
                                                    if((casa == 2) && (campo[2][0].nomeC == "-")){
                                                        acabaC = 1;
                                                        campo[2][0].nomeC = p2[iAux].nome;
                                                        campo[2][0].indice = iAux;
                                                        
                                                    }else{
                                                        if((casa == 3) && (campo[3][0].nomeC == "-")){
                                                            acabaC = 1;
                                                            campo[3][0].nomeC = p2[iAux].nome;
                                                            campo[3][0].indice = iAux;
                                                            
                                                        }else{
                                                            cout << "\nA casa escolhida nao esta disponível. Tente novamente\n";
                                                            
                                                        }
                                                    }
                                                }
                                                
                                            }while(((casa <= 0) || (casa >= 4)) || (acabaC == 0));
                                            
                                            cP2[pokemon].nome = "-";
                                            
                                            system ("pause");
        									system ("cls");
                                        }
                                    }
                                }
                            }else{
                                if(iAux == 8){
                                    cout << "\nVoce usou a carta 'Pesquisa de Professor' e ganhou 2 cartas!\n";
                                    
                                    for(i=0;i<2;i++){
                                        if(cont2 >= 13){
                                            cout << "\nNao ha mais cartas em seu baralho\n";
                                            system ("pause");
                                            system ("cls");
                                            
                                        }else{
                                        	system ("pause");
        									system ("cls");
                                            cards = 0+rand()%13;
                                            if(p2[cards].pegou == 0){
                                                cP2[cont2].nome = p2[cards].nome; cP2[cont2].ataque1 = p2[cards].ataque1; cP2[cont2].fraco = p2[cards].fraco; cP2[cont2].descricao = p2[cards].descricao; cP2[cont2].vida = p2[cards].vida; cP2[cont2].dano1 = p2[cards].dano1; cP2[cont2].suporte = p2[cards].suporte; cP2[cont2].custo1 = p2[cards].custo1; cP2[cont2].mover = p2[cards].mover; cP2[cont2].pegou = 1; p2[cards].pegou = 1; cP2[cont2].evolucao = p2[cards].evolucao;
                                                if(cP2[cont2].suporte == 1){
                                                    cout << "\nVoce Puxou uma carta e pegou...:\n" << cP2[cont2].nome; cout << "\n\n" << cP2[cont2].descricao;
                                                    system ("pause");
                                                    system ("cls");
                                                    
                                                }else{
                                                    cout << "\nVoce puxou uma carta e pegou...:\n\n" << cP2[cont2].nome << "\tHP: " << cP2[cont2].vida; cout << "\n\n" << cP2[cont2].ataque1 << "\tDMG: " << cP2[cont2].dano1 << "\n" << "\nCusto para usar o ataque:\t" << cP2[cont2].custo1; cout << "\nFraquesa: " << cP2[cont2].fraco; cout << "\n\nEnergia para mover: " << cP2[cont2].mover;
                                                    system ("pause");
                                                    system ("cls");
                                                    
                                                }
                                            }else{
                                                i--;
                                                cont2--;
                                            }
                                            cont2++;
                                        }
                                    }
                                    
                                    cP2[pokemon].nome = "-";
                                    
                                }else{
                                    if((iAux == 9) || (iAux == 10)){
                                        if(p2[iAux].nome == "Blaine"){
                                            cout << "\nVoce usou a carta 'Blaine'! Por este turno, Ninetales, Magmar e Rapidash vão dar 30 de dano a mais!\n";
                                            blaine = 1;
                                            cP2[pokemon].nome = "-";
                                            system ("pause");
                                            system ("cls");
                                            
                                        }else{
                                            if(p2[iAux].nome == "Misty"){
                                                cout << "\nEscolha o Pokemon que deseja usar esta carta:\n";
                                                
                                                if((campo[1][0].nomeC == "-") && (campo[2][0].nomeC == "-") && (campo[3][0].nomeC == "-")){
                                                    cout << "\nVoce nao tem cartas em campo\n";
                                                    
                                                }else{
                                                    for(i=1;i<4;i++){
                                                        if(campo[i][0].nomeC == "-"){
                                                            
                                                        }else{
                                                            cout << i << ". " << campo[i][0].nomeC << "\n";
                                                        }
                                                        
                                                    }
                                                    
                                                    do{
                                                        cin >> eMisty;
                                                        
                                                        if((eMisty <= 0) || (eMisty >=4)){
                                                            cout << "\nNumero invalido. Tente novamente\n";
                                                            
                                                        }else{
                                                            if(campo[eMisty][0].nomeC == "-"){
                                                                cout << "\nEsta casa esta vazia. Tente novamente\n";
                                                                
                                                            }
                                                        }
                                                        
                                                    }while((eMisty <= 0) || (eMisty >=4) || (campo[eMisty][0].nomeC == "-"));
                                                    
                                                    cout << "\nAgora uma moeda vai ser jogada ate sair coroa. Para cada cara, coloque uma Energia sera colocada no pokemon escolhido.!\n";
                                                    
                                                    system ("pause");
                                                    system ("cls");
                                                    
                                                    do{
                                                        moeda = 1+rand()%2;
                                                        
                                                        if(moeda == 1){
                                                            cout << "\nCaiu cara!\n";
                                                            campo[eMisty][0].energia++;
                                                            
                                                        }else{
                                                            cout << "\nCaiu coroa\n";
                                                            
                                                        }
                                                    }while(moeda == 1);
                                                    
                                                    cout << "\nA energia do seu " << campo[eMisty][0].nomeC << " agora é de " << campo[eMisty][0].energia;
                                                    cP2[pokemon].nome = "-";
                                                    
                                                    system ("pause");
                                                    system ("cls");
                                                    
                                                }
                                            }else{
                                                if(p2[iAux].nome == "Erika"){
                                                    cout << "\nEscolha o Pokemon que deseja usar esta carta:\n";
                                                    
                                                    if((campo[1][0].nomeC == "-") && (campo[2][0].nomeC == "-") && (campo[3][0].nomeC == "-")){
                                                        cout << "\nVoce nao tem cartas em campo\n";
                                                        
                                                    }else{
                                                        for(i=1;i<4;i++){
                                                            if(campo[i][0].nomeC == "-"){
                                                                
                                                            }else{
                                                                cout << i << ". " << campo[i][0].nomeC << "\n";
                                                            }
                                                            
                                                        }
                                                        
                                                        do{
                                                            cin >> eErika;
                                                            
                                                            if((eErika <= 0) || (eErika >=4)){
                                                                cout << "\nNumero invalido. Tente novamente\n";
                                                                
                                                            }else{
                                                                if(campo[eErika][0].nomeC == "-"){
                                                                    cout << "\nEsta casa esta vazia. Tente novamente\n";
                                                                    
                                                                }
                                                            }
                                                        }while((eErika <= 0) || (eErika >=4) || (campo[eErika][0].nomeC == "-"));
                                                        
                                                        cout << "\n" << campo[eErika][0].nomeC << " recuperou 50 de HP!\n";
                                                        
                                                        for(i=0;i<14;i++){
                                                            if(campo[eErika][0].nomeC == p2[i].nome){
                                                                p2[i].vida = p2[i].vida + 50;
                                                                
                                                            }
                                                        }
                                                        
                                                        cP2[pokemon].nome = "-";
                                                        
                                                        system ("pause");
                                                        system ("cls");
                                                        
                                                    }
                                                }
                                            }
                                        }
                                        
                                    }else{
                                        if((iAux == 11) || (iAux == 12)){
                                            cout << "\nEscolha o Pokemon que voce deseja usar esta carta:\n";
                                            
                                            if((campo[1][0].nomeC == "-") && (campo[2][0].nomeC == "-") && (campo[3][0].nomeC == "-")){
                                                cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                                
                                            }else{
                                                for(i=1;i<4;i++){
                                                    if(campo[i][0].nomeC == "-"){
                                                        
                                                    }else{
                                                        cout << i << ". " << campo[i][0].nomeC << "\n";
                                                        
                                                    }
                                                  
                                                }
                                                
                                                do{
                                                    cin >> pocao;
                                                    
                                                    if((pocao <= 0) || (pocao >=4)){
                                                        cout << "\nNumero invalido. Tente novamente\n";
                                                        
                                                    }else{
                                                        if(campo[pocao][0].nomeC == "-"){
                                                            cout << "\nCasa vazia. Tente novamente\n";
                                                            
                                                        }
                                                    }
                                                    
                                                }while((pocao <= 0) || (pocao >=4) || (campo[pocao][0].nomeC == "-"));
                                                
                                                cout << "\n" << campo[pocao][0].nomeC << "recuperou 20 de HP!\n";
                                                
                                                for(i=0;i<14;i++){
                                                    if(campo[pocao][0].nomeC == p2[i].nome){
                                                        p2[i].vida += 20;
                                                        
                                                    }
                                                }
                                                
                                                cP2[pokemon].nome = "-";
                                                
                                                system ("pause");
                                                system ("cls");
                                                
                                            }
                                            
                                        }else{
                                            if(iAux == 13){
                                                cout << "\nEscolha o Pokemon que voce deseja usar esta carta:\n";
                                                
                                                if((campo[1][0].nomeC == "-") && (campo[2][0].nomeC == "-") && (campo[3][0].nomeC == "-")){
                                                    cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                                    
                                                }else{
                                                    for(i=1;i<4;i++){
                                                        if(campo[i][0].nomeC == "-"){
                                                            
                                                        }else{
                                                            cout << i << ". " << campo[i][0].nomeC << "\n";
                                                            
                                                        }
                                                      
                                                    }
                                                    
                                                    do{
                                                        cin >> velocidade;
                                                        
                                                        if((velocidade <= 0) || (velocidade >=4)){
                                                            cout << "\nNumero invalido. Tente novamente\n";
                                                            
                                                        }else{
                                                            if(campo[velocidade][0].nomeC == "-"){
                                                                cout << "\nCasa vazia. Tente novamente\n";
                                                                
                                                            }
                                                        }
                                                        
                                                    }while((velocidade <= 0) || (velocidade >=4) || (campo[velocidade][0].nomeC == "-"));
                                                    
                                                    cout << "\n" << campo[velocidade][0].nomeC << " precidara de -1 energia para se mover\n";
                                                    
                                                    for(i=0;i<14;i++){
                                                        if(campo[velocidade][0].nomeC == p2[i].nome){
                                                            p2[i].mover = p2[i].mover - 1;
                                                        }
                                                    }
                                                    
                                                    cP2[pokemon].nome = "-";
                                                    
                                                    system ("pause");
                                                    system ("cls");
                                                    
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            

                            
                            acabaP = 0; acabaC = 0;
                            
                        }else{
                            if(escolha == 2){
                                if(primeiro == 1){
                                    cout << "\nVoce nao pode atacar no primeiro turno\n";
                                    system ("pause");
                                    system ("cls");
                                    
                                }else{
                                    cout << "\nEscolha o Pokemon que voce quer usar para atacar\n";
                                    
                                    if((campo[1][0].nomeC == "-") && (campo[2][0].nomeC == "-") && (campo[3][0].nomeC == "-")){
                                        cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                        
                                    }else{
                                        for(i=1;i<4;i++){
                                            if(campo[i][0].nomeC == "-"){
                                                
                                            }else{
                                                cout << i << ". " << campo[i][0].nomeC << "\n";
                                            }
                                            
                                        }
                                        
                                        do{
                                            cin >> ataca;
                                            
                                            if((ataca <=0) || (ataca >=4)){
                                                cout << "\nCasa invalida. Tente novamente\n";
                                                
                                            }else{
                                                if(campo[ataca][0].nomeC == "-"){
                                                    cout << "\nCasa vazia. Tente novamente\n";
                                                    
                                                }else{
                                                    if(campo[ataca][0].atacou == 1){
                                                        cout << "\nEste Pokemon ja atacou neste turno\n";
                                                        
                                                    }
                                                }
                                            }
                                        }while((ataca <= 0) || (ataca >= 4) || (campo[ataca][0].nomeC == "-") || (campo[ataca][0].atacou == 1));
                                        
                                        if(campo[ataca][0].energia < p1[campo[ataca][0].indice].custo1){
                                            cout << "\nSeu Pokemon nao tem energia suficiente para atacar\n";
                                            
                                        }else{
                                            campo[ataca][0].atacou = 1;
                                            if(campo[ataca][1].nomeC == "-"){
                                                for(i=0;i<14;i++){
                                                    if(campo[ataca][0].nomeC == p2[i].nome){
                                                        danoAux = p2[i].dano1;
                                                        if(blaine == 1){
                                                            if((p2[i].nome == "Ninetales") || (p2[i].nome == "Magmar") || (p2[i].nome == "Rapidash")){
                                                                p2[i].dano1 = p2[i].dano1 + 30;
                                                                
                                                            }
                                                        }
                                                        vidap1 = vidap1 - p2[i].dano1;
                                                        cout << "\nSeu " << p2[i].nome << " deu " << p2[i].dano1 << " no Player2, ficando com " << vidap1 << "\n";
                                                        p2[i].dano1 = danoAux;
                                                        
                                                        system ("pause");
                                                        system ("cls");
                                                        
                                                    }
                                                }
                                            }else{
                                                for(i=0;i<14;i++){
                                                    if(campo[ataca][0].nomeC == p2[i].nome){
                                                        for(j=0;j<14;j++){
                                                            if(campo[ataca][1].nomeC == p1[j].nome){
                                                                danoAux = p2[i].dano1;
                                                                if((p2[i].fraco == "Agua") && (p1[j].fraco == "Fogo")){
                                                                    if(blaine == 1){
                                                                        if((p2[i].nome == "Ninetales") || (p2[i].nome == "Magmar") || (p2[i].nome == "Rapidash")){
                                                                            p2[i].dano1 = p2[i].dano1 + 30;
                                                                        }
                                                                    }
                                                                    p2[i].dano1 = p2[i].dano1 * 2;
                                                                    p1[j].vida = p1[j].vida - p2[i].dano1;
                                                                    cout << "\nSeu ataque foi super efetivo!\n";
                                                                    cout << "\nSeu " << p2[i].nome << " deu " << p2[i].dano1 << " no " << p1[j].nome << " do Player2, deixando ele com " << p1[j].vida << " de HP\n";
                                                                    p2[i].dano1 = danoAux;
                                                                    system ("pause");
                                                                    system ("cls");
                                                                    
                                                                }else{
                                                                    if((p2[i].fraco == "Folha") && (p1[j].fraco == "Agua")){
                                                                        if(blaine == 1){
                                                                            if((p2[i].nome == "Ninetales") || (p2[i].nome == "Magmar") || (p2[i].nome == "Rapidash")){
                                                                                p2[i].dano1 = p2[i].dano1 + 30;
                                                                                
                                                                            }
                                                                        }
                                                                        p2[i].dano1 = p2[i].dano1 * 2;
                                                                        p1[j].vida = p1[j].vida - p2[i].dano1;
                                                                        cout << "\nSeu ataque foi super efetivo!\n";
                                                                        cout << "\nSeu " << p2[i].nome << " deu " << p2[i].dano1 << " no " << p1[j].nome << " do Player2, deixando ele com " << p1[j].vida << " de HP\n";
                                                                        p2[i].dano1 = danoAux;
                                                                        system ("pause");
                                                                        system ("cls");
                                                                        
                                                                    }else{
                                                                        if((p2[i].fraco == "Fogo") && (p1[j].fraco == "Folha")){
                                                                            if(blaine == 1){
                                                                                if((p2[i].nome == "Ninetales") || (p2[i].nome == "Magmar") || (p2[i].nome == "Rapidash")){
                                                                                   p2[i].dano1 = p2[i].dano1 + 30;
                                                                                   
                                                                                }
                                                                            }
                                                                            p2[i].dano1 = p2[i].dano1 * 2;
                                                                            p1[j].vida = p1[j].vida - p2[i].dano1;
                                                                            cout << "\nSeu ataque foi super efetivo!\n";
                                                                            cout << "\nSeu " << p2[i].nome << " deu " << p2[i].dano1 << " no " << p1[j].nome << " do Player2, deixando ele com " << p1[j].vida << " de HP\n";
                                                                            p2[i].dano1 = danoAux;
                                                                            system ("pause");
                                                                            system ("cls");
                                                                            
                                                                        }else{
                                                                            if(blaine == 1){
                                                                                if((p2[i].nome == "Ninetales") || (p2[i].nome == "Magmar") || (p2[i].nome == "Rapidash")){
                                                                                    p2[i].dano1 = p2[i].dano1 + 30;
                                                                                    
                                                                                }
                                                                            }
                                                                            p1[j].vida = p1[j].vida - p2[i].dano1;
                                                                            cout << "\nSeu " << p2[i].nome << " deu " << p2[i].dano1 << " no " << p1[j].nome << " do Player2, deixando ele com " << p1[j].vida << " de HP\n";
                                                                            p2[i].dano1 = danoAux;
                                                                            system ("pause");
                                                                            system ("cls");
                                                                            
                                                                        }
                                                                    }
                                                                }
                                                                
                                                                if(p1[j].vida <= 0){
                                                                    cout << "\nO " << p2[j].nome << " do Player2 desmaiou!\n";
                                                                    campo[ataca][1].nomeC = "-"; campo[ataca][1].energia = 0;
                                                                    
                                                                    system ("pause");
                                                                    system ("cls");
                                                                    
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
                                if(escolha == 3){
                                    if(moverF == 1){
                                        cout << "\nVoce ja moveu uma carta nesse round\n";
                                        
                                    }else{
                                        cout << "\nEscolha o Pokemon que voce quer mover de posição\n";
                                        
                                        if((campo[1][0].nomeC == "-") && (campo[2][0].nomeC == "-") && (campo[3][0].nomeC == "-")){
                                            cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                            
                                        }else{
                                            for(i=1;i<4;i++){
                                                if(campo[i][0].nomeC == "-"){
                                                    
                                                }else{
                                                    cout << i << ". " << campo[i][0].nomeC << "\n";
                                                }
                                                
                                            }
                                            
                                            do{
                                                cin >> mexer;
                                                
                                                if((mexer <= 0) || (mexer >= 4)){
                                                    cout << "\nCasa invalida. Tente novamente\n";
                                                    
                                                }else{
                                                    if(campo[mexer][0].nomeC == "-"){
                                                        cout << "\nCasa vazia. Tente novamente\n";
                                                        
                                                    }
                                                }
                                                
                                            }while ((mexer <= 0) || (mexer >=4) || (campo[mexer][0].nomeC == "-"));
                                            
                                            if(campo[mexer][0].energia < p1[campo[mexer][0].indice].mover){
                                                cout << "\nEnergia insuficiente\n";
                                                
                                            }else{
                                                moverF = 1;
                                                if(mexer == 1){
                                                    auxNome = campo[1][0].nomeC; campo[1][0].nomeC = campo[2][0].nomeC; campo[2][0].nomeC = auxNome;
                                                    auxInd = campo[1][0].indice; campo[1][0].indice = campo[2][0].indice; campo[2][0].indice = auxInd;
                                                    auxEne = campo[1][0].energia; campo[1][0].energia = campo[2][0].energia; campo[2][0].energia = auxEne;
                                                    
                                                }else{
                                                    if(mexer == 2){
                                                        do{
                                                            cout << "\nMover para esquerda ou para Direita? (1 - Esquerda / 2 - Direita)\n";
                                                            cin >> escolhaM;
                                                            
                                                            if((escolhaM <=0) || (escolhaM >= 3)){
                                                                cout << "\nNumero Inavlido. Tente novamente\n";
                                                                
                                                            }
                                                        }while ((escolhaM <=0) || (escolhaM >= 3));
                                                        
                                                        if(escolhaM == 1){
                                                            auxNome = campo[2][0].nomeC; campo[2][0].nomeC = campo[1][0].nomeC; campo[1][0].nomeC = auxNome;
                                                            auxInd = campo[2][0].indice; campo[2][0].indice = campo[1][0].indice; campo[1][0].indice = auxInd;
                                                            auxEne = campo[2][0].energia; campo[2][0].energia = campo[1][0].energia; campo[1][0].energia = auxEne;
                                                            
                                                        }else{
                                                            auxNome = campo[2][0].nomeC; campo[2][0].nomeC = campo[3][0].nomeC; campo[3][0].nomeC = auxNome;
                                                            auxInd = campo[2][0].indice; campo[2][0].indice = campo[3][0].indice; campo[3][0].indice = auxInd;
                                                            auxEne = campo[2][0].energia; campo[2][0].energia = campo[3][0].energia; campo[3][0].energia = auxEne;
                                                            
                                                        }
                                                    }else{
                                                        auxNome = campo[3][0].nomeC; campo[3][0].nomeC = campo[2][0].nomeC; campo[2][0].nomeC = auxNome;
                                                        auxInd = campo[3][0].indice; campo[3][0].indice = campo[2][0].indice; campo[2][0].indice = auxInd;
                                                        auxEne = campo[3][0].energia; campo[3][0].energia = campo[2][0].energia; campo[2][0].energia = auxEne;
                                                        
                                                    }
                                                }
                                                
                                            }
                                        }
                                    }
                                    

                                    
                                    system ("pause");
                                    system ("cls");
                                    
                                }else{
                                    if(escolha == 4){
                                        cout << "\nEscolha qual carta voce quer checar:\n";
                                        
                                        if((campo[1][0].nomeC == "-") && (campo[2][0].nomeC == "-") && (campo[3][0].nomeC == "-")){
                                            cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                            
                                        }else{
                                            for(i=1;i<4;i++){
                                                if(campo[i][0].nomeC == "-"){
                                                    
                                                }else{
                                                    cout << i << ". " << campo[i][0].nomeC << "\n";
                                                }
                                                
                                            }
                                            
                                            do{
                                                cin >> checar;
                                                
                                                if((checar <= 0) || (checar >=4)){
                                                    cout << "\nCasa invalida. Tente novamente\n";
                                                    
                                                }else{
                                                    if(campo[checar][0].nomeC == "-"){
                                                        cout << "\nCasa vazia. Tente novamente\n";
                                                        
                                                    }
                                                }
                                                
                                            }while ((checar <= 0) || (checar >=4) || (campo[checar][0].nomeC == "-"));
                                            
                                            for(i=0;i<14;i++){
                                                if(campo[checar][0].nomeC == p2[i].nome){
                                                    cout << "\n\n" << p2[i].nome << "\tHP: " << p2[i].vida; cout << "\n\n" << p2[i].ataque1 << "\tDMG: " << p2[i].dano1 << "\n" << "\nEnergia necessaria para usar o ataque\t" << p2[i].custo1; cout << "\nFraqueza: " << p2[i].fraco; cout << "\n\nEnergia para mover: " << p2[i].mover; cout << "\nEnergia presente na carta: " << campo[checar][0].energia << "\n\n";
                                                    system ("pause");
                                                    system ("cls");
                                                    
                                                }
                                            }
                                            
                                        }

                                        
                                        
                                        
                                        
                                    }else{
                                        if(escolha == 5){
                                            if(energiaF == 1){
                                                cout << "\nVoce ja adicionou uma energia neste turno\n";
                                                
                                            }else{
                                                energiaF = 1;
                                                cout << "\nEscolha qual carta voce quer adicionar a energia:\n";
                                                
                                                if((campo[1][0].nomeC == "-") && (campo[2][0].nomeC == "-") && (campo[3][0].nomeC == "-")){
                                                    cout << "\nVoce nao tem nenhum Pokemon em campo\n";
                                                    
                                                }else{
                                                    for(i=1;i<4;i++){
                                                        if(campo[i][0].nomeC == "-"){
                                                            
                                                        }else{
                                                            cout << i << ". " << campo[i][0].nomeC << "\n";
                                                        }
                                                        
                                                    }
                                                    do{
                                                        cin >> energy;
                                                        
                                                        if((energy <= 0) || (energy >=4)){
                                                            cout << "\nCasa invalida. Tente novamente\n";
                                                            
                                                        }else{
                                                            if(campo[energy][0].nomeC == "-"){
                                                                cout << "\nCasa vazia. Tente novamente\n";
                                                                
                                                            }
                                                        }
                                                        
                                                    }while ((energy <= 0) || (energy >=4) || (campo[energy][0].nomeC == "-"));
                                                    
                                                    cout << "\nEnergia adicionada com sucesso!\n";
                                                    
                                                    campo[energy][0].energia = campo[energy][0].energia + 1;
                                                    
                                                    cout << "\nSeu " << campo[energy][0].nomeC << " agora tem " << campo[energy][0].energia << " de energia!\n";
                                                    system ("pause");
                                                    system ("cls");
                                                    
                                                }
                                            }
                                            

                                            
                                        }else{
                                            acabaT = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }while ((acabaT == 0) && (vidap1 > 0) && (vidap2 > 0));
                    
                    system ("pause");
                    system ("cls");
                    
                    primeiro = 0; acaba = 0; energiaF = 0; acabaT = 0; blaine = 0; moverF = 0; campo[1][0].atacou = 0; campo[2][0].atacou = 0; campo[3][0].atacou = 0; campo[1][0].evoluiu = 0; campo[2][0].evoluiu = 0; campo[3][0].evoluiu = 0;
                    
                    if(velo == 1){
                        velo = 0;
                        for(i=0;i<14;i++){
                            if(campo[velocidade][0].nomeC == p2[i].nome){
                                p2[i].mover = p2[i].mover + 1;
                            }
                        }
                        
                    }
                    
                    if(vidap1 <= 0){
                        cout << "\nO Jogador2 ganhou a Batalha!\n";
                        acabaB = 1;
                        
                    }else{
                        if(vidap2 <= 0){
                            cout << "\nO Jogador1 ganhou a Batalha\n";
                            acabaB = 1;
                            
                        }
                    }
                }
            }
        }
    }
}


