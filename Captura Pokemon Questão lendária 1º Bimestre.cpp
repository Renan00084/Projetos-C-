/*Durante sua jornada, o treinador encontra uma rota especial onde 
pode escolher a raridade do Pokémon que deseja enfrentar. 
As opções de raridade são: Comum = 255, Incomum = 126,
Raro = 64 e Lendário = 5, 
e cada uma delas possui uma taxa base de captura distinta, 
o que influencia diretamente na probabilidade de sucesso da tentativa. 
Após selecionar a raridade desejada, um Pokémon será sorteado 
aleatoriamente dentre os disponíveis naquela categoria.

Em seguida, o treinador deverá escolher uma Pokébola para a tentativa de captura.
As opções disponíveis são: Ultra Ball, Heavy Ball, Love Ball, Dive Ball e Dark Ball,
cada uma com modificadores específicos que afetam a chance de sucesso dependendo 
de fatores como peso do Pokémon, tipo, horário e gênero.

Antes de calcular a chance de captura, o treinador deverá informar 
algumas características do Pokémon enfrentado: o valor de HP máximo 
e o HP atual, a condição de status (se está dormindo, congelado, paralisado, queimado, etc.),
o tipo do Pokémon, seu peso em quilogramas, seu gênero e o gênero do treinador, 
além de especificar se o encontro está ocorrendo durante o dia ou à noite.

Com base nesses dados, o programa aplicará a fórmula de captura 
utilizada nas gerações III a V dos jogos Pokémon. Essa fórmula 
considera os pontos de vida do Pokémon, sua taxa base de captura 
de acordo com a raridade, os modificadores da Pokébola usada e os 
efeitos de status, resultando em um valor de captura (O). A partir 
desse valor, o programa calculará a chance final de captura, 
determinando se o Pokémon será capturado com sucesso ou não.

R = taxa base de captura do Pokémon

Pokébola	Condição	Multiplicador ?bola
Ultra Ball	Sempre	1.5
Heavy Ball	Se peso > 200kg: 2.0, 100–200kg: 1.5, <100kg: 1.0	1.0–2.0
Love Ball	Gênero oposto ao do treinador: 2.0 / mesmo gênero: 0.8 / sem gênero: 1.0	0.8–2.0
Dive Ball	Se tipo == "Água"	3.5 ou 1.0
Dark Ball	Noite: 3.0 / Dia: 1.0	1.0 ou 3.0
Status	Modificador ?status
Dormindo ou Congelado	2.0
Paralisado, Queimado etc.	1.5
Nenhum	1.0

Formula: chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int pokemon, taxaBase, tipo, pokebolaD, sorte, masterBall;
    
    char escolhaRaridade, pokebola, status, generoInimigo, genero, tempo;
    
    float peso, hpAtual, hpMax, multiplicador, statusNum, chanceCaptura; 
    
    unsigned seed = time(0);
    
    srand(seed);
    
    pokemon = 1+ rand() % 5;
    
    sorte = 1+ rand() % 100;
    
    cout << "Ola Treinador!\n";
    
    cout << "\nEscolha a raridade do Pokemon que deseja capturar\n";
    cout << "\nC = Comum\nI = Incomum\nR = Raro\nL = Lendario\n";
    cin >> escolhaRaridade;
    
    if((escolhaRaridade == 'c') || (escolhaRaridade == 'C')){
        
        taxaBase = 255;
        
        if(pokemon == 1){
            cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Pidgey selvagem apareceu!\n";
            
        }else{
            if(pokemon == 2){
                cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Rattata selvagem apareceu!\n";
                
            }else{
                if(pokemon == 3){
                    cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Magikarp selvagem apareceu!\n";
                   
                }else{
                    if(pokemon == 4){
                        cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Tentacool selvagem apareceu!\n";
                        
                    }else{
                        cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Caterpie selvagem apareceu!\n";
                        
                    }
                }
            }
        }
        
        cout << "\nInforme a vida maxima do Pokemon encontrado:\n";
        cin >> hpMax;
        
        cout << "\nInforme a vida atual do Pokemon encontrado:\n";
        cin >> hpAtual;
        
        cout << "\nInforme a condicao de status:\n";
        cout << "\nD = Dormindo\nC = Congelado\nP = Paralisado\nQ = Queimando\nE = Envenenado\nN = Nenhum\n";
        cin >> status;
        
        if(((status == 'D') || (status == 'd')) || ((status == 'C') || (status == 'c'))){
            statusNum = 2;
            
        }else{
            if(((status == 'P') || (status == 'p')) || ((status == 'q') || (status == 'Q')) || ((status == 'e') || (status == 'E'))){
                statusNum = 1.5;
                
            }else{
                statusNum = 1;
                
            }
        }
        
        cout << "\nEscolha qual Pokebola voce vai usar para capturar o Pokemon:\n";
        cout << "\nU = Ultra Ball\nH = Heavy Ball\nL = Love Ball\nD = Dive Ball / Dark Ball\n";
        cin >> pokebola;
        
        if((pokebola =='d') || (pokebola == 'D')){
            cout << "\nEspecifique a Pokebola: (1 = Dive Ball / 2 = Dark Ball)\n";
            cin >> pokebolaD;
            
        }
        
        if((pokebola == 'U') || (pokebola == 'u')){
            cout << "\nA Pokebola escolhida foi a Ultra Ball!\n";
            
            multiplicador = 1.5;
            
        }else{
            if((pokebola == 'h') || (pokebola == 'H')){
                cout << "\nA Pokebola escolhida foi a Heavy Ball!\n";
                
                cout << "\nInforme o peso do Pokemon encontrado (em kg):\n";
                cin >> peso;
                
                if(peso >= 200){
                    multiplicador = 2;
                    
                }else{
                    if(peso >= 100){
                        multiplicador = 1.5;
                        
                    }else{
                        multiplicador = 1;
                        
                    }
                }
                
            }else{
                if((pokebola == 'l') || (pokebola == 'L')){
                    cout << "\nA Pokebola escolhida foi a Love Ball!\n";
                    
                    cout << "\nInforme o genero do Pokemon encontrado:\n";
                    cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                    cin >> generoInimigo;
                    
                    cout << "\nInforme o genero do seu Pokemon:\n";
                    cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                    cin >> genero;
                    
                    if(genero == generoInimigo){
                        multiplicador = 0.8;
                        
                    }else{
                        if((((genero == 'M' ) || (genero == 'm')) && ((generoInimigo == 'f') || (generoInimigo == 'F'))) || (((genero == 'f') || (genero == 'F'))) && (((generoInimigo == 'm') || (generoInimigo == 'M')))){
                            multiplicador = 2;
                            
                        }else{
                            if(((genero == 's') || (genero == 'S')) || ((generoInimigo == 's') || (generoInimigo == 'S'))){
                                multiplicador = 1;
                                
                            }
                        }
                    }
                    
                }else{
                    if(pokebolaD == 1){
                        cout << "\nA Pokebola escolhida foi a Dive Ball!\n";
                        
                        cout << "\nInforme se o tipo do Pokemon e do tipo agua (1 = sim / 2 = nao):\n";
                        cin >> tipo;
                        
                        if(tipo == 1){
                            multiplicador = 3.5;
                            
                        }else{
                            multiplicador = 1;
                            
                        }
                        
                    }else{
                        if(pokebolaD == 2){
                            cout << "\nA Pokebola escolhida foi a Dark Ball!\n";
                            
                            cout << "\nInforme se esta de dia ou de noite:\n";
                            cout << "\nD = Dia\nN = Noite\n";
                            cin >> tempo;
                            
                            if((tempo == 'd') || (tempo == 'D')){
                                multiplicador = 1;
                                
                            }else{
                                if((tempo == 'n') || (tempo == 'N')){
                                    multiplicador = 3;
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
        
        chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
        
        if(chanceCaptura >= 60){
            cout << "\nParabens! O Pokemon foi capturado com sucesso\n";
            
        }else{
            cout << "\nO Pokemon saiu da Pokebola e fugiu...\n";
            
        }
        
        cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
        
    }else{
        if((escolhaRaridade == 'I') || (escolhaRaridade == 'i')){
            taxaBase = 126;
         
            if(pokemon == 1){
                cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Growlithe selvagem apareceu!\n";
              
            }else{
                if(pokemon == 2){
                cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Eevee selvagem apareceu!\n";
                
                }else{
                    if(pokemon == 3){
                        cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Machop selvagem apareceu!\n";
                     
                    }else{
                        if(pokemon == 4){
                            cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Psyduck selvagem apareceu!\n";
                            
                        }else{
                            cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Froakie selvagem apareceu!\n";
                            
                        }
                    }
                }
            }
            
            cout << "\nInforme a vida maxima do Pokemon encontrado:\n";
            cin >> hpMax;
           
            cout << "\nInforme a vida atual do Pokemon encontrado:\n";
            cin >> hpAtual;
           
            cout << "\nInforme a condicao de status:\n";
            cout << "\nD = Dormindo\nC = Congelado\nP = Paralisado\nQ = Queimando\nE = Envenenado\nN = Nenhum\n";
            cin >> status;
           
            if(((status == 'D') || (status == 'd')) || ((status == 'C') || (status == 'c'))){
                statusNum = 2;
                
            }else{
                if(((status == 'P') || (status == 'p')) || ((status == 'q') || (status == 'Q')) || ((status == 'e') || (status == 'E'))){
                    statusNum = 1.5;
                  
                }else{
                    statusNum = 1;
                  
                }
            }
           
            cout << "\nEscolha qual Pokebola voce vai usar para capturar o Pokemon:\n";
            cout << "\nU = Ultra Ball\nH = Heavy Ball\nL = Love Ball\nD = Dive Ball / Dark Ball\n";
            cin >> pokebola;
            
            if((pokebola =='d') || (pokebola == 'D')){
                cout << "\nEspecifique a Pokebola: (1 = Dive Ball / 2 = Dark Ball)\n";
                cin >> pokebolaD;
             
            }
          
            if((pokebola == 'U') || (pokebola == 'u')){
                cout << "\nA Pokebola escolhida foi a Ultra Ball!\n";
               
                multiplicador = 1.5;
               
            }else{
                if((pokebola == 'h') || (pokebola == 'H')){
                    cout << "\nA Pokebola escolhida foi a Heavy Ball!\n";
                 
                    cout << "\nInforme o peso do Pokemon encontrado (em kg):\n";
                   cin >> peso;
                   
                    if(peso >= 200){
                        multiplicador = 2;
                      
                    }else{
                        if(peso >= 100){
                            multiplicador = 1.5;
                          
                        }else{
                            multiplicador = 1;
                         
                        }
                    }
                   
                }else{
                    if((pokebola == 'l') || (pokebola == 'L')){
                        cout << "\nA Pokebola escolhida foi a Love Ball!\n";
                      
                        cout << "\nInforme o genero do Pokemon encontrado:\n";
                        cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                        cin >> generoInimigo;
                      
                        cout << "\nInforme o genero do seu Pokemon:\n";
                        cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                        cin >> genero;
                      
                        if(genero == generoInimigo){
                            multiplicador = 0.8;
                           
                        }else{
                            if((((genero == 'M' ) || (genero == 'm')) && ((generoInimigo == 'f') || (generoInimigo == 'F'))) || (((genero == 'f') || (genero == 'F'))) && (((generoInimigo == 'm') || (generoInimigo == 'M')))){
                                multiplicador = 2;
                                    
                            }else{
                                if(((genero == 's') || (genero == 'S')) || ((generoInimigo == 's') || (generoInimigo == 'S'))){
                                    multiplicador = 1;
                                   
                                }
                            }
                        }
                     
                    }else{
                        if(pokebolaD == 1){
                            cout << "\nA Pokebola escolhida foi a Dive Ball!\n";
                            
                            cout << "\nInforme se o tipo do Pokemon e do tipo agua (1 = sim / 2 = nao):\n";
                            cin >> tipo;
                         
                            if(tipo == 1){
                                multiplicador = 3.5;
                              
                            }else{
                                multiplicador = 1;
                               
                            }
                            
                        }else{
                            if(pokebolaD == 2){
                                cout << "\nA Pokebola escolhida foi a Dark Ball!\n";
                              
                                cout << "\nInforme se esta de dia ou de noite:\n";
                                cout << "\nD = Dia\nN = Noite\n";
                                cin >> tempo;
                             
                                if((tempo == 'd') || (tempo == 'D')){
                                    multiplicador = 1;
                                 
                                }else{
                                    if((tempo == 'n') || (tempo == 'N')){
                                        multiplicador = 3;
                                      
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
          
            if(chanceCaptura >= 60){
                cout << "\nParabens! O Pokemon foi capturado com sucesso\n";
             
            }else{
                cout << "\nO Pokemon saiu da Pokebola e fugiu...\n";
             
            }
         
            cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
         
        }else{
            if((escolhaRaridade == 'R') || (escolhaRaridade == 'r')){
                taxaBase = 64;
                
                if(pokemon == 1){
                    cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Dratini selvagem apareceu!\n";
                  
                }else{
                    if(pokemon == 2){
                        cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Lapras selvagem apareceu!\n";
                    
                    }else{
                        if(pokemon == 3){
                            cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Larvitar selvagem apareceu!\n";
                            
                        }else{
                            if(pokemon == 4){
                                cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Mimikyu selvagem apareceu!\n";
                                
                            }else{
                                cout << "\nVoce estava andando sobre uma grama alta ate que...\nUm Vaporeon selvagem apareceu!\n";
                                
                            }
                        }
                    }
                }
                
                cout << "\nInforme a vida maxima do Pokemon encontrado:\n";
                cin >> hpMax;
             
                cout << "\nInforme a vida atual do Pokemon encontrado:\n";
                cin >> hpAtual;
                
                cout << "\nInforme a condicao de status:\n";
                cout << "\nD = Dormindo\nC = Congelado\nP = Paralisado\nQ = Queimando\nE = Envenenado\nN = Nenhum\n";
                cin >> status;
                
                if(((status == 'D') || (status == 'd')) || ((status == 'C') || (status == 'c'))){
                    statusNum = 2;
                    
                }else{
                    if(((status == 'P') || (status == 'p')) || ((status == 'q') || (status == 'Q')) || ((status == 'e') || (status == 'E'))){
                        statusNum = 1.5;
                        
                    }else{
                        statusNum = 1;
                        
                    }
                }
              
                cout << "\nEscolha qual Pokebola voce vai usar para capturar o Pokemon:\n";
                cout << "\nU = Ultra Ball\nH = Heavy Ball\nL = Love Ball\nD = Dive Ball / Dark Ball\n";
                cin >> pokebola;
             
                if((pokebola =='d') || (pokebola == 'D')){
                    cout << "\nEspecifique a Pokebola: (1 = Dive Ball / 2 = Dark Ball)\n";
                    cin >> pokebolaD;
                 
                }
             
                if((pokebola == 'U') || (pokebola == 'u')){
                    cout << "\nA Pokebola escolhida foi a Ultra Ball!\n";
                    
                    multiplicador = 1.5;
                    
                }else{
                    if((pokebola == 'h') || (pokebola == 'H')){
                        cout << "\nA Pokebola escolhida foi a Heavy Ball!\n";
                      
                        cout << "\nInforme o peso do Pokemon encontrado (em kg):\n";
                        cin >> peso;
                     
                        if(peso >= 200){
                            multiplicador = 2;
                          
                        }else{
                            if(peso >= 100){
                                multiplicador = 1.5;
                              
                            }else{
                                multiplicador = 1;
                               
                            }
                        }
                     
                    }else{
                        if((pokebola == 'l') || (pokebola == 'L')){
                            cout << "\nA Pokebola escolhida foi a Love Ball!\n";
                         
                            cout << "\nInforme o genero do Pokemon encontrado:\n";
                            cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                            cin >> generoInimigo;
                            
                            cout << "\nInforme o genero do seu Pokemon:\n";
                            cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                            cin >> genero;
                           
                            if(genero == generoInimigo){
                                multiplicador = 0.8;
                               
                            }else{
                                if((((genero == 'M' ) || (genero == 'm')) && ((generoInimigo == 'f') || (generoInimigo == 'F'))) || (((genero == 'f') || (genero == 'F'))) && (((generoInimigo == 'm') || (generoInimigo == 'M')))){
                                    multiplicador = 2;
                                 
                                }else{
                                    if(((genero == 's') || (genero == 'S')) || ((generoInimigo == 's') || (generoInimigo == 'S'))){
                                        multiplicador = 1;
                                     
                                    }
                                }
                            }
                           
                        }else{
                            if(pokebolaD == 1){
                                cout << "\nA Pokebola escolhida foi a Dive Ball!\n";
                              
                                cout << "\nInforme se o tipo do Pokemon e do tipo agua (1 = sim / 2 = nao):\n";
                                cin >> tipo;
                               
                                if(tipo == 1){
                                    multiplicador = 3.5;
                                 
                                }else{
                                    multiplicador = 1;
                                 
                                }
                             
                            }else{
                                if(pokebolaD == 2){
                                    cout << "\nA Pokebola escolhida foi a Dark Ball!\n";
                                  
                                    cout << "\nInforme se esta de dia ou de noite:\n";
                                    cout << "\nD = Dia\nN = Noite\n";
                                    cin >> tempo;
                                    
                                    if((tempo == 'd') || (tempo == 'D')){
                                        multiplicador = 1;
                                       
                                    }else{
                                        if((tempo == 'n') || (tempo == 'N')){
                                            multiplicador = 3;
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
              
                chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
             
                if(chanceCaptura >= 60){
                    cout << "\nParabens! O Pokemon foi capturado com sucesso!!\n";
                    
                }else{
                    cout << "\nO Pokemon saiu da Pokebola e fugiu...\n";
                   
                }
             
                cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                
            }else{
                if((escolhaRaridade == 'L') || (escolhaRaridade == 'l')){
                    taxaBase = 5;
                    
                    cout << "\n(Sorte = " << sorte << ")\n";
                    
                    if(sorte >= 80){
                        cout << "\nEnquanto andava, voce encontrou um Master Ball largada no chao\n";
                        
                        masterBall = 1;
                        
                    }
                
                    if(pokemon == 1){
                        cout << "\nVoce estava andando sobre uma grama alta ate que...\nDe repente, o ceu escurece e uma forte chuva começa a cair...\nUm Kyogre selvagem apareceu!\n";
                        
                    }else{
                        if(pokemon == 2){
                            cout << "\nVoce estava andando sobre uma grama alta ate que...\nDe repente, o clima muda para uma atmosfera calma e solene...\nUm Suicune selvagem apareceu!\n";
                          
                        }else{
                            if(pokemon == 3){
                                cout << "\nVoce estava andando sobre uma grama alta ate que...\nDe repente, algo com uma aura psiquica começa a flutuar a sua frente...\nUm MewTwo selvagem apareceu!\n";
                                
                            }else{
                                if(pokemon == 4){
                                    cout << "\nVoce estava andando sobre uma grama alta ate que...\nDe repente, voce escuta um rugido celestial e uma forte ventania começa...\nUm Rayquaza selvagem apareceu!\n";
                                    
                                }else{
                                    cout << "\nVoce estava andando sobre uma grama alta ate que...\nDe repente, o ambiente se enche de raios e trovoes...\nUm Zapdos selvagem apareceu!\n";
                                }
                            }
                        }
                    }
                    
                    if(masterBall == 1){
                        cout << "\nInforme a vida maxima do Pokemon encontrado:\n";
                        cin >> hpMax;
                 
                        cout << "\nInforme a vida atual do Pokemon encontrado:\n";
                        cin >> hpAtual;
                   
                        cout << "\nInforme a condicao de status:\n";
                        cout << "\nD = Dormindo\nC = Congelado\nP = Paralisado\nQ = Queimando\nE = Envenenado\nN = Nenhum\n";
                        cin >> status;
                   
                        if(((status == 'D') || (status == 'd')) || ((status == 'C') || (status == 'c'))){
                            statusNum = 2;
                       
                        }else{
                            if(((status == 'P') || (status == 'p')) || ((status == 'q') || (status == 'Q')) || ((status == 'e') || (status == 'E'))){
                                statusNum = 1.5;
                            
                            }else{
                                statusNum = 1;
                         
                            }
                        }
                  
                        cout << "\nEscolha qual Pokebola voce vai usar para capturar o Pokemon:\n";
                        cout << "\nU = Ultra Ball\nH = Heavy Ball\nL = Love Ball\nD = Dive Ball / Dark Ball\nM = Master Ball\n";
                        cin >> pokebola;
                 
                        if((pokebola =='d') || (pokebola == 'D')){
                            cout << "\nEspecifique a Pokebola: (1 = Dive Ball / 2 = Dark Ball)\n";
                            cin >> pokebolaD;
                     
                        }
                 
                        if((pokebola == 'U') || (pokebola == 'u')){
                            cout << "\nA Pokebola escolhida foi a Ultra Ball!\n";
                     
                            multiplicador = 1.5;
                            
                            chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
                        
                        }else{
                            if((pokebola == 'h') || (pokebola == 'H')){
                                cout << "\nA Pokebola escolhida foi a Heavy Ball!\n";
                         
                                cout << "\nInforme o peso do Pokemon encontrado (em kg):\n";
                                cin >> peso;
                         
                                if(peso >= 200){
                                    multiplicador = 2;
                                
                                }else{
                                    if(peso >= 100){
                                        multiplicador = 1.5;
                                 
                                    }else{
                                        multiplicador = 1;
                                    
                                    }
                                }
                                
                                chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
                           
                            }else{
                                if((pokebola == 'l') || (pokebola == 'L')){
                                    cout << "\nA Pokebola escolhida foi a Love Ball!\n";
                               
                                    cout << "\nInforme o genero do Pokemon encontrado:\n";
                                    cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                                    cin >> generoInimigo;
                               
                                    cout << "\nInforme o genero do seu Pokemon:\n";
                                    cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                                    cin >> genero;
                              
                                    if(genero == generoInimigo){
                                        multiplicador = 0.8;
                                 
                                    }else{
                                        if((((genero == 'M' ) || (genero == 'm')) && ((generoInimigo == 'f') || (generoInimigo == 'F'))) || (((genero == 'f') || (genero == 'F'))) && (((generoInimigo == 'm') || (generoInimigo == 'M')))){
                                            multiplicador = 2;
                                        
                                        }else{
                                            if(((genero == 's') || (genero == 'S')) || ((generoInimigo == 's') || (generoInimigo == 'S'))){
                                                multiplicador = 1;
                                            
                                            }
                                        }
                                    }
                                    
                                    chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
                            
                                }else{
                                    if(pokebolaD == 1){
                                        cout << "\nA Pokebola escolhida foi a Dive Ball!\n";
                                 
                                        cout << "\nInforme se o tipo do Pokemon e do tipo agua (1 = sim / 2 = nao):\n";
                                        cin >> tipo;
                                  
                                        if(tipo == 1){
                                            multiplicador = 3.5;
                                       
                                        }else{
                                            multiplicador = 1;
                                        
                                        }
                                        
                                        chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
                                    
                                    }else{
                                        if(pokebolaD == 2){
                                            cout << "\nA Pokebola escolhida foi a Dark Ball!\n";
                                     
                                            cout << "\nInforme se esta de dia ou de noite:\n";
                                            cout << "\nD = Dia\nN = Noite\n";
                                            cin >> tempo;
                                        
                                            if((tempo == 'd') || (tempo == 'D')){
                                                multiplicador = 1;
                                          
                                            }else{
                                                if((tempo == 'n') || (tempo == 'N')){
                                                    multiplicador = 3;
                                            
                                                }
                                            }
                                            
                                            chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
                                            
                                        }else{
                                            if((pokebola == 'm') || (pokebola =='M')){
                                                cout << "\nA Pokebola escolhida foi a Master Ball!\n";
                                                
                                                chanceCaptura = 999999;
                                                
                                            } 
                                        }
                                    }
                                }
                            }
                        }
                   

                        if(chanceCaptura >= 60){
                            cout << "\nParabens! O Pokemon foi capturado com sucesso!!\n";
                        
                        }else{
                            cout << "\nO Pokemon saiu da Pokebola e fugiu...\n";
                       
                        }
                  
                        cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                        
                        return 0;

                    }
                    
                    cout << "\nInforme a vida maxima do Pokemon encontrado:\n";
                    cin >> hpMax;
                 
                    cout << "\nInforme a vida atual do Pokemon encontrado:\n";
                    cin >> hpAtual;
                   
                    cout << "\nInforme a condicao de status:\n";
                    cout << "\nD = Dormindo\nC = Congelado\nP = Paralisado\nQ = Queimando\nE = Envenenado\nN = Nenhum\n";
                    cin >> status;
                   
                    if(((status == 'D') || (status == 'd')) || ((status == 'C') || (status == 'c'))){
                        statusNum = 2;
                       
                    }else{
                        if(((status == 'P') || (status == 'p')) || ((status == 'q') || (status == 'Q')) || ((status == 'e') || (status == 'E'))){
                            statusNum = 1.5;
                            
                        }else{
                            statusNum = 1;
                         
                        }
                    }
                  
                    cout << "\nEscolha qual Pokebola voce vai usar para capturar o Pokemon:\n";
                    cout << "\nU = Ultra Ball\nH = Heavy Ball\nL = Love Ball\nD = Dive Ball / Dark Ball\n";
                    cin >> pokebola;
                 
                    if((pokebola =='d') || (pokebola == 'D')){
                        cout << "\nEspecifique a Pokebola: (1 = Dive Ball / 2 = Dark Ball)\n";
                        cin >> pokebolaD;
                     
                    }
                 
                    if((pokebola == 'U') || (pokebola == 'u')){
                        cout << "\nA Pokebola escolhida foi a Ultra Ball!\n";
                     
                        multiplicador = 1.5;
                        
                    }else{
                        if((pokebola == 'h') || (pokebola == 'H')){
                            cout << "\nA Pokebola escolhida foi a Heavy Ball!\n";
                         
                            cout << "\nInforme o peso do Pokemon encontrado (em kg):\n";
                            cin >> peso;
                         
                            if(peso >= 200){
                                multiplicador = 2;
                                
                            }else{
                                if(peso >= 100){
                                    multiplicador = 1.5;
                                 
                                }else{
                                    multiplicador = 1;
                                    
                                }
                            }
                           
                        }else{
                            if((pokebola == 'l') || (pokebola == 'L')){
                                cout << "\nA Pokebola escolhida foi a Love Ball!\n";
                               
                                cout << "\nInforme o genero do Pokemon encontrado:\n";
                                cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                                cin >> generoInimigo;
                               
                                cout << "\nInforme o genero do seu Pokemon:\n";
                                cout << "\nM = Macho\nF = Femea\nS = Sem genero\n";
                                cin >> genero;
                              
                                if(genero == generoInimigo){
                                    multiplicador = 0.8;
                                 
                                }else{
                                    if((((genero == 'M' ) || (genero == 'm')) && ((generoInimigo == 'f') || (generoInimigo == 'F'))) || (((genero == 'f') || (genero == 'F'))) && (((generoInimigo == 'm') || (generoInimigo == 'M')))){
                                        multiplicador = 2;
                                        
                                    }else{
                                        if(((genero == 's') || (genero == 'S')) || ((generoInimigo == 's') || (generoInimigo == 'S'))){
                                            multiplicador = 1;
                                            
                                        }
                                    }
                                }
                           
                            }else{
                                if(pokebolaD == 1){
                                    cout << "\nA Pokebola escolhida foi a Dive Ball!\n";
                                 
                                    cout << "\nInforme se o tipo do Pokemon e do tipo agua (1 = sim / 2 = nao):\n";
                                    cin >> tipo;
                                  
                                    if(tipo == 1){
                                        multiplicador = 3.5;
                                       
                                    }else{
                                        multiplicador = 1;
                                        
                                    }
                                    
                                }else{
                                    if(pokebolaD == 2){
                                        cout << "\nA Pokebola escolhida foi a Dark Ball!\n";
                                     
                                        cout << "\nInforme se esta de dia ou de noite:\n";
                                        cout << "\nD = Dia\nN = Noite\n";
                                        cin >> tempo;
                                        
                                        if((tempo == 'd') || (tempo == 'D')){
                                            multiplicador = 1;
                                          
                                        }else{
                                            if((tempo == 'n') || (tempo == 'N')){
                                                multiplicador = 3;
                                            
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                   
                    chanceCaptura = ((((3 * hpMax) - (2 * hpAtual)) * taxaBase * multiplicador) / (3 * hpMax)) * statusNum;
                 
                    if(chanceCaptura >= 60){
                        cout << "\nParabens! O Pokemon foi capturado com sucesso!!\n";
                        
                    }else{
                        cout << "\nO Pokemon saiu da Pokebola e fugiu...\n";
                       
                    }
                  
                    cout << "\n(A chance de captura foi de " << chanceCaptura << ")\n";
                    
                }
            }
        }
    }
}












