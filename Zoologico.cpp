#include <stdio.h>


int main()
{
	
	int chaveAnimal(char animal[]); //função que compara a quantidade de letras de uma string
	bool comparaAnimal(char animalVetor[], char animalVetorBanco[]); //função que compara duas string
	
	
	char animal[15],animalBanco[15];
	int quantidade;
	float preco,diario,mensal,custoMensal,kiloBanco;
	bool condicional = false;
	
	
	
	
	FILE *file;
	file = fopen("Animais.txt", "r"); // COMANDO PARA ACESSAR O ARQUIVO TXT
	
	printf("================ ENTRADA ======================\n\n");
	printf("- Tipo de Animal: ");
	scanf("%s",&animal);
	
	
	// FOR PARA RODAR LINHA A LINHA DO ARQUIVO TXT
	for(int c=0; c < 50; c++)
	{
		
		fscanf(file, "%s %f",&animalBanco, &kiloBanco);	// COMANDO PARA LER UMA LINHA DO ARQUIVO TXT	
		condicional = comparaAnimal(animal,animalBanco);// USANDO A FUNÇÃO DE COMPARAR STRING PARA COMPARAR O VALOR INSERIDO,COM O VALOR DO ARQUIVO TXT
		if(condicional)
		{
			break;	
		}	
	}
	fclose(file); // FECHA O ARQUIVO TXT
	
	if(condicional != true) // CONDICIONAL SE O VALOR DIGITADO É IGUAL O DO ARQUIVO 
	{
		printf("Animal nao cadastrado em nosso sistema!!\n");
		return 0;
	}
	else
	{
		
		printf("- Quantidade de animais: ");
		scanf("%d",&quantidade);
		printf("- Custo estimado por kilo de comida: ");
		scanf("%f",&preco);
		
		diario = quantidade * kiloBanco;
		mensal = diario * 30;
		custoMensal = mensal * preco;
		
		printf("\n\n================ SAIDA ======================\n");
		printf("\n- Quantidade por de kilo por animal: %.2f",kiloBanco);
		printf("\n- Quantidade por dia: %.3f",diario);
		printf("\n- Quantidade por mes: %.3f",mensal);
		printf("\n- Custo estimado por mes: %.2f",custoMensal);
	}

}








int chaveAnimal(char animalVetor[])
{
	int c=0;
	
	while (animalVetor[c] != '\0')
	{
		c++;
		
	}
	
	return c;
}

bool comparaAnimal(char animalVetor[], char animalVetorBanco[])
{
	int numberAnimal=0,numberAnimalBanco=0,contador=0;
	
	numberAnimal = chaveAnimal(animalVetor);
	numberAnimalBanco = chaveAnimal(animalVetorBanco);
	
	
	
	if(numberAnimal == numberAnimalBanco)
	{
		for(int c=0; c < numberAnimalBanco; c++)
		{
			if(animalVetorBanco[c] == animalVetor[c])
			{
				contador++;
			}
		}
		if(contador == numberAnimal)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
		{
			return false;
		}
}
