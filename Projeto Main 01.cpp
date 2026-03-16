/* MACKENZIE HIGIENÓPOLIS - 02P11 - 2° SEMESTRE - ALG & PROG II
NOMES: 
Eric Kanomata Schutz Cabrera | RA: 10736688
Pedro Henrique da Silva Lima | RA: 10744246 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para criar e atualizar o Polinômio
void attPoli (int poli[], int * grau) {
	printf("\nDigite o grau do polinomio: ");
	scanf("%d", grau);
	printf("\n");
	for (int i = *grau; i >= 0; i--) {
		if (i > 1) {
			printf("Digite o coeficiente de x^%d: ", i);
			scanf("%d", &poli[i]);
		} else if (i == 1) {
			printf("Digite o coeficiente de x: ");
			scanf("%d", &poli[i]);
		} else if (i == 0) {
			printf("Digite o termo indepente: ");
			scanf("%d", &poli[i]);
		}
	}
	printf("\n");
}

// Função para imprimir o Polinômio
void printPoli (int poli[], int grau) {
	
	int printed = 0;
	printf("> ");
	
	for (int a = grau; a >= 0; a--) { // Loop para apresentar o polinômio em uma linha
		// Condicional n.1 para evitar erros quando o grau do polinômio for muito baixo (1° ou 2° grau)
		if (poli[a] == 0) {
			continue;
		}
		if (printed && poli[a] > 0) {
			printf(" +");
		}
		if (a == 0) {
			printf(" %d", poli[a]);
		} else if (a == 1) {
			printf(" %dx", poli[a]);
		} else if (a > 1) {
			printf(" %dx^%d", poli[a], a);
		}
		printed = 1;
	}
	printf("\n");
}

// Função para calcular o valor do Polinômio
void valorPoli (int poli1[], int grau1, int x) {
	
	float resultados[50] = {}; // Array para poder somar a linha de resultados
	int r1 = 0; // Variável para adicionar itens na lista de resultados
	float resultado_valor = 0; // Váriavel para apresentar o resultado do valor total somado 
	int printed = 0;

	printf("\n"); // Nova linha 
	printf("P(%d) = ", x);
	for (int a = grau1; a >= 0; a--) { // Loop para apresentar a primeira linha do cálculo \ Substituição
		if (printed && poli1[a] > 0) {
			printf(" +");
		}
		if (poli1[a] == 0) {
			continue;
		} else if (a == 0) {
			printf(" %d", poli1[a]);
		} else if (a == 1) {
			printf(" %d(%d)", poli1[a], x);
		} else if (a > 1) {
			printf(" %d(%d)^%d", poli1[a], x, a);
		}
		printed = 1;
	}
	
	if (grau1 < 2) { // Condicional para evitar erro de printar duas vezes a mesma linha (Em casos de grau < 2)
		printf("");
	} else {
		printed = 0;
		printf("\n\n"); // Nova linha 
		printf("P(%d) = ", x);
		for (int a = grau1; a >= 0; a--) { // Loop para apresentar a segunda linha do cálculo \ Resultado das Potências
			if (printed && poli1[a] > 0) {
				printf(" +");
			}
			if (poli1[a] == 0) {
				continue;
			} else if (a == 0) {
				printf(" %d", poli1[a]);
			} else if (a == 1) {
				printf(" %d(%d)", poli1[a], x);
			} else if (a > 1){
				printf(" %d", poli1[a]);
				printf("(%.0f)", pow(x, a));
			}
		printed = 1;
		}
	}
	
	printf("\n\n"); // Nova linha
	printf("P(%d) = ", x);
	printed = 0;
	for (int a = grau1; a >= 0; a--) { // Loop para apresentar a terceira linha do cálculo \ Resultados das Multiplicações
		if (poli1[a] == 0) {
			continue;
		} else if (a == 0) {
			resultados[r1] = poli1[a]; // Adicionando os resultados na lista para somar todos os itens depois
			printf(" %d", poli1[a]);
		} else if (a == 1) {
			resultados[r1] = poli1[a] * x; // Adicionando os resultados na lista para somar todos os itens depois
			if (resultados[r1] > 0 && printed) {
				printf(" +");
			}
			printf(" %d", poli1[a] * x);
		} else if (a > 1){
			resultados[r1] = poli1[a] * pow(x, a); // Adicionando os resultados na lista para somar todos os itens depois
			if (resultados[r1] > 0 && printed) {
				printf(" +");
			}
			printf(" %.0f", poli1[a] * pow(x, a));
		}
		printed = 1;
		r1++;
	}
	
	printf("\n\n"); // Nova linha
	for (int a = grau1; a >= 0; a--) { // Loop para apresentar a última linha do cálculo \ Resultado das Somas
			resultado_valor = resultado_valor + resultados[a];
	}
	
	printf("P(%d) =  %.0f", x, resultado_valor);
}

// Função para calcular a soma de Polinômios
void somaPoli(int poli1[], int grau1, int poli2[], int grau2) {
	
    int maiorGrau = (grau1 > grau2) ? grau1 : grau2; // Modelo simplificado de "if-else"; if (grau1 > grau2), maiorGrau = grau1, else maiorGrau = grau2
    int printed = 0; // Criação de variável para adição do símbolo "+" sem dar erros
    
    printf("\n"); // Nova linha
    
    for (int a = maiorGrau; a >= 0; a--) { // Loop para a primeira linha (Visualização das somas)
    	
    	int authPoli1 = a <= grau1; // Criação de varíavel para evitar erros durante a execução
    	int authPoli2 = a <= grau2; // (Verifica se o n° atual existe dentro das listas)
    	
    	if (poli1[a] == 0 && poli2[a] == 0) { // Se ambos os números das listas forem 0, pula
    		continue;
		}
		
    	if (authPoli1 && authPoli2) {
    		if (printed) {
    			printf(" + "); // Printa o sinal de adição entre as operações SE já tiver sido printado um número antes
			}
    		if (a == 0) {
				printf("(%d", poli1[a]);
				if (poli2[a] >= 0) { // Condição para não adicionar o sinal de adição quando o número já tiver o sinal negativo 
					printf(" + ");
				}
				printf("%d)",poli2[a]);
			} else if (a == 1) {
				printf("(%d", poli1[a]);
				if (poli2[a] >= 0) { // Condição para não adicionar o sinal de adição quando o número já tiver o sinal negativo 
					printf(" + ");
				}
				printf("%d)x",poli2[a]);
			} else if (a > 1) {
				printf("(%d", poli1[a]);
				if (poli2[a] >= 0) { // Condição para não adicionar o sinal de adição quando o número já tiver o sinal negativo 
					printf(" + ");
				}
				printf("%d)x^%d",poli2[a], a);
			}
			
		} else if (authPoli1 && !authPoli2) { // Verifica os números que estão fora do range do Polinomio 2
				if (printed && poli1[a] > 0) {
					printf(" + ");
				}
				if (a == 0) {
					printf("%d", poli1[a]);
				} else if (a == 1) {
					printf("%dx", poli1[a]);
				} else if (a >= 1) {
					printf("%dx^%d", poli1[a], a);
				}
		} else if (!authPoli1 && authPoli2) { // Verifica os números que estão fora do range do Polinomio 1
				if (printed && poli2[a] > 0) {
					printf(" + ");
				}
				if (a == 0) {
					printf("%d", poli2[a]);
				} else if (a == 1) {
					printf("%dx", poli2[a]);
				} else if (a >= 1) {
					printf("%dx^%d", poli2[a], a);
				}
		}
		printed = 1;
	}
	
	printf("\n\n"); // Nova linha
	printed = 0;
	for (int a = maiorGrau; a >= 0; a--) { // Loop para a segunda linha (Resultado das somas)
    	
    	int authPoli1 = a <= grau1; // Criação de varíavel para evitar erros durante a execução
    	int authPoli2 = a <= grau2; // (Verifica se o n° atual existe dentro das listas)
    	
    	if (poli1[a] == 0 && poli2[a] == 0) { // Se ambos os números das listas forem 0, pula
    		continue;
		}
		
    	if (authPoli1 && authPoli2) {
    		if (printed) {
    			printf(" + "); // Printa o sinal de adição entre as operações SE já tiver sido printado um número antes
			}
    		if (a == 0) {
				printf("%d", poli1[a] + poli2[a]);
			} else if (a == 1) {
				printf("%dx", poli1[a] + poli2[a]);
			} else if (a > 1) {
				printf("%dx^%d", poli1[a] + poli2[a], a);
			}
			
		} else if (authPoli1 && !authPoli2) {
				if (printed && poli1[a] > 0) {
					printf(" + ");
				}
				if (a == 0) {
					printf("%d", poli1[a]);
				} else if (a == 1) {
					printf("%dx", poli1[a]);
				} else if (a > 1) {
					printf("%dx^%d", poli1[a], a);
				}
		} else if (!authPoli1 && authPoli2) {
				if (printed && poli2[a] > 0) {
					printf(" + ");
				}
				if (a == 0) {
					printf("%d", poli2[a]);
				} else if (a == 1) {
					printf("%dx", poli2[a]);
				} else if (a > 1) {
					printf("%dx^%d", poli2[a], a);
				}
		}
		printed = 1;
	}
}
	
// Função para calcular a multiplicação de Polinômios
void multiPoli (int poli1[], int grau1, int poli2[], int grau2) {
	
	int printed = 0; // Reiniciando Variável
	int grauResultante = grau1 + grau2; // Tamanho máximo da multiplicação de dois polinômios é a soma dos graus
	int poliResultante[grauResultante + 1]; // Criação da array para o polinômio resultante
	
	printf("\n"); // Nova linha
	printf("P(x) * Q(x) = "); // Expressão a ser calculada
	
	for (int a = grau1; a >= 0; a--) { // Loop para a primeira parte da primeira linha (antes do parênteses)
		if (poli1[a] == 0) { // Se o número for zero, pula
			continue;
		}
		if (poli1[a] > 0 && printed) { // Adiciona sinal se o número não for negativo e se não for o primeiro
			printf("+ ");
		}
		if (a == 0) {
			printf("%d(", poli1[a]); // Termo Independente
		} else if (a == 1) {
			printf("%dx(", poli1[a]); // X sem potência (Penúltimo)
		} else if (a > 1) {
			printf("%dx^%d(", poli1[a], a); // X com potência (Todos tirando último e penúltimo)
		}
		for (int b = grau2; b >= 0; b--) { // Parte de dentro do parênteses
				if (poli2[b] == 0) { // Se for zero, pula
					continue;
				}
				if (b == 0) {
					printf("%d", poli2[b]); // Termo Independente
				} else if (b == 1) {
					printf("%dx", poli2[b]); // X sem potência (Penúltimo)
				} else if (b > 1) {
					printf("%dx^%d", poli2[b], b); // X com potência (Todos tirando último e penúltimo)
				}
				if (poli2[b] > 0 && poli2[b - 1] > 0 && b != 0) {
					printf(" + ");
				}
			}
		printf(") "); // Fecha parênteses	
		printed = 1;	
	}
	
	printf("\n\n"); // Nova linha
	printf("P(x) * Q(x) = "); // Expressão a ser calculada
	
	printed = 0; // Reiniciando variável
	
	for (int a = grau1; a >= 0; a--) { // Loop para a segunda linha 
		if (poli1[a] == 0) { // Se for zero, pula
			continue;
		}
		if (poli1[a] > 0 && printed) { // Adiciona sinal se não for negativo e se não for o primeiro
			printf(" + ");
		}
		if (a == 0) {
			for (int b = grau2; b >= 0; b--) {
				printf("%d * ", poli1[a]); // Adiciona o termo independente vezes os números do outro polinômio a serem multiplicados
				if (poli2[b] == 0) { // Se for zero, pula
					continue;
				}
				if (b == 0) {
					printf("%d ", poli2[b]); // Termo independente
				} else if (b == 1) {
					printf("%dx ", poli2[b]); // X sem potência (Penúltimo)
				} else if (b > 1) {
					printf("%dx^%d ", poli2[b], b); // X com potência (Todos menos último e penúltimo)
				}
				if (poli2[b] > 0 && poli2[b - 1] > 0 && b != 0 && poli1[a] > 0) {
					printf("+ ");
				}
			}
		} else if (a == 1) {
			for (int b = grau2; b >= 0; b--) {
				printf("%dx * ", poli1[a]); // Adiciona o "x sem potência" vezes os números do outro polinômio a serem multiplicados
				if (poli2[b] == 0) { // Se for zero, pula
					continue;
				}
				if (b == 0) {
					printf("%d ", poli2[b]); // Termo independente
				} else if (b == 1) {
					printf("%dx ", poli2[b]); // X sem potência (Penúltimo)
				} else if (b > 1) {
					printf("%dx^%d ", poli2[b], b); // X com potência (Todos menos último e penúltimo)
				}
				// Adição de sinal se: poli1 e poli2 forem > 0, se não for o último da poli2 e se o próximo número for positivo
				if (poli2[b] > 0 && poli2[b - 1] > 0 && b != 0 && poli1[a] > 0) { 
					printf("+ ");
				}
			}
		} else if (a > 1) {
			for (int b = grau2; b >= 0; b--) {
				printf("%dx^%d * ", poli1[a], a) ; // Adiciona o "x com potência" vezes os números do outro polinômio a serem multiplicados
				if (poli2[b] == 0) {
					continue;
				}
				if (b == 0) {
					printf("%d ", poli2[b]); // Termo independente 
				} else if (b == 1) {
					printf("%dx ", poli2[b]); // X sem potência (Penúltimo)
				} else if (b > 1) {
					printf("%dx^%d ", poli2[b], b); // X com potência (Todos menos último e penúltimo)
				}
				// Adição de sinal se: poli1 e poli2 forem > 0, se não for o último da poli2 e se o próximo número for positivo
				if (poli2[b] > 0 && poli2[b - 1] > 0 && b != 0 && poli1[a] > 0) {
					printf("+ ");
				}
			}
		} 
		printed = 1;
	}
	
	printf("\n\n"); // Nova linha
	printf("P(x) * Q(x) = "); // Expressão a ser calculada
	
	printed = 0; // Reiniciando variável
	
	for (int a = grau1; a >= 0; a--) { // Loop para a terceira linha 
		if (poli1[a] == 0) { // Se for zero, pula
			continue;
		}
		if (poli1[a] > 0 && printed) { // Adiciona sinal se não for negativo e se não for o primeiro
			printf(" + ");
		}
		if (a == 0) {
			for (int b = grau2; b >= 0; b--) {
				// printf("%dx^%d * ", poli1[a], a) ; // Adiciona o "x com potência" vezes os números do outro polinômio a serem multiplicados
				if (poli2[b] == 0) {
					continue;
				}
				if (b == 0) {
					printf("%d", poli1[a] * poli2[b]);
				} else if (b == 1) {
					printf("%dx", poli1[a] * poli2[b]);
				} else if (b > 1) {
					printf("%dx^%d", poli1[a] * poli2[b], b);
				}
				// Adição de sinal se: poli1 e poli2 forem > 0, se não for o último da poli2 e se o próximo número for positivo
				if (poli2[b] > 0 && poli2[b - 1] > 0 && b != 0 && poli1[a] > 0) {
					printf(" + ");
				}
			}
		} else if (a == 1) {
			for (int b = grau2; b >= 0; b--) {
				// printf("%dx^%d * ", poli1[a], a) ; // Adiciona o "x com potência" vezes os números do outro polinômio a serem multiplicados
				if (poli2[b] == 0) {
					continue;
				}
				if (b == 0) {
					printf("%dx", poli1[a] * poli2[b]);
				} else if (b >= 1) {
					printf("%dx^%d", poli1[a] * poli2[b], a + b);
				} 
				// Adição de sinal se: poli1 e poli2 forem > 0, se não for o último da poli2 e se o próximo número for positivo
				if (poli2[b] > 0 && poli2[b - 1] > 0 && b != 0 && poli1[a] > 0) {
					printf(" + ");
				}
			}
		} else if (a > 1) {
			for (int b = grau2; b >= 0; b--) {
				// printf("%dx^%d * ", poli1[a], a) ; // Adiciona o "x com potência" vezes os números do outro polinômio a serem multiplicados
				if (poli2[b] == 0) {
					continue;
				}	
				printf("%dx^%d", poli1[a] * poli2[b], a + b);
				
				// Adição de sinal se: poli1 e poli2 forem > 0, se não for o último da poli2 e se o próximo número for positivo
				if (poli2[b] > 0 && poli2[b - 1] > 0 && b != 0 && poli1[a] > 0) {
					printf(" + ");
				}
			}
		}
		printed = 1; 
	}
	
	printed = 0; // Reiniciando Variável
	
		
	for (int a = 0; a <= grauResultante; a++) { // Zerando a array (Estava dando output errado)
	    poliResultante[a] = 0; 
	}
	
	for (int a = 0; a <= grau1; a++) { // Percorre cada n° em Poli 1
	    for (int b = 0; b <= grau2; b++) { // Percorre cada n° em Poli 2
	        poliResultante[a + b] += poli1[a] * poli2[b]; 
	        // Adiciona e soma o resultado dentro da lista resultante (como é o mesmo índice, eles vão se somando)
		}
	}
	
	printf("\n\n"); // Nova linha
	printf("P(x) * Q(x) = "); 
	
	for (int c = grauResultante; c >= 0; c--) { // Loop para a quarta linha (Ordenação)
	    if (poliResultante[c] == 0) { // Se for zero, pula
			continue;
		}
	
	    if (poliResultante[c] > 0 && printed) { // Adiciona símbolo "+" se o n° atual for positivo e não for o primeiro
	        	printf(" + ");
	    }
	    if (c == 0) { // Termo Independente
	        printf("%d", poliResultante[c]);
	    }
	    else if (c == 1) { // X sem potência (Penúltimo)
	        printf("%dx", poliResultante[c]);
	    }
	    else { // X com potência (todos menos último e antepenúltimo)
	        printf("%dx^%d", poliResultante[c], c);
	    }
	    printed = 1;
	}
}

// Função Principal 
int main () {
	
	// Variáveis
	char enter;
	int option, x;
	int poli1[50], poli2 [50], grau1, grau2;
	int poli3[50], grau3; // Polinomio e grau resultantes
	bool loop = true;
	int test;

	// Loop para o Menu
	for (loop = true; loop = true;) {
		system("cls"); // Limpar o terminal tendo como finalidade única a estética, já que a utilização prolongada desse programa pode gerar código demais
		printf("Calculadora de Polinomios\n\n1. Calcular o valor de Polinomios\n2. Calcular a soma de Polinomios\n3. Calcular a multiplicacao de Polinomios\n4. Encerrar o programa\n\n> ");
		scanf("%d", &option);
		system("cls"); // Limpa terminal
		if (option > 4 || option < 1) {
			
			printf("Opcao Invalida! Pressione ENTER para voltar ao menu\n"); // Input errado
			scanf("%c", &enter); 
			scanf("%c", &enter); // Colocar duas vezes (motivo indefinido, mas acreditamos que o scanf já lia o ENTER de quando colocávamos a opcção desejada, ao invés de ler depois
			
		} else if (option == 1) { // Calcular valor do Polinômio
		
			printf("> Calcular o Valor de um Polinomio\n"); 
			attPoli(poli1, &grau1); // Atualizar o polinomio
			
			// Input para o valor de x
			printf("\nDigite um valor para (x): ");
			scanf("%d", &x);
			
			//Funções
			printPoli(poli1, grau1);
			valorPoli(poli1, grau1, x);
			
			// Return do menu
			printf("\n\n> Pressione ENTER para voltar ao menu\n");
			scanf("%c", &enter); 
			scanf("%c", &enter); // Colocar duas vezes (motivo indefinido, mas acreditamos que o scanf já lia o ENTER de quando colocávamos a opcção desejada, ao invés de ler depois)
			
		} else if (option == 2) { // Calcular Soma de Polinômios
			system("cls"); // Limpa Terminal
			
			// Atualizar ou Inserir Polinômios 1 e 2
			printf("Polinomio 1: "); // Atualizar o Polinomio 1
			attPoli(poli1, &grau1);
			
			printf("Polinomio 2: "); // Ataulizar o Polinomio 2
			attPoli(poli2, &grau2);
			
			// Funções
			printPoli(poli1, grau1); // Imprimir Polinomio 1
			printPoli(poli2, grau2); // Imprimir Polinomio 2
			somaPoli(poli1, grau1, poli2, grau2); // Fazer a soma de P1 e P2
			printf("\n\n> Pressione ENTER para voltar ao menu\n");
			scanf("%c", &enter);
			scanf("%c", &enter); // Colocar duas vezes (motivo indefinido, mas acreditamos que o scanf já lia o ENTER de quando colocávamos a opcção desejada, ao invés de ler depois)
			
		} else if (option == 3) { // Calcular Multiplicação de Polinômios
			system("cls"); // Limpa Terminal
			
			// Atualizar ou Inserir Polinômios 1 e 2
			printf("Polinomio 1: "); // Atualizar o Polinomio 1
			attPoli(poli1, &grau1);
			
			printf("Polinomio 2: "); // Ataulizar o Polinomio 2
			attPoli(poli2, &grau2);
			
			// Funções 
			printPoli(poli1, grau1); // Imprimir Polinomio 1
			printPoli(poli2, grau2); // Imprimir Polinomio 2
			multiPoli(poli1, grau1, poli2, grau2); // Fazer a multiplicação de P1 e P2
			printf("\n\n> Pressione ENTER para voltar ao menu\n");
			scanf("%c", &enter); 
			scanf("%c", &enter); // Colocar duas vezes (motivo indefinido, mas acreditamos que o scanf já lia o ENTER de quando colocávamos a opcção desejada, ao invés de ler depois)
			
		} else if (option == 4) { // Encerrar o programa
			printf("\nPROGRAMA ENCERRADO...");
			loop = false; // Quebra de loop e fim do programa
		} 
	}
}
