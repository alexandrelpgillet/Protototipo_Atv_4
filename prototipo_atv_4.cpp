#include <iostream>
#include <stdio.h>

using namespace std;




int armazenamento(string C , string M , string F , char E[] , char S[] , int D , int MM , int AA , int CNPJ)

{

    char *c , *m , *f;
    
    c = &C[0];
    m = &M[0];
    f = & F[0];

    

    FILE *pont_arq;

    pont_arq = fopen("dados_lote.txt" , "w");

    if(pont_arq == NULL)
    {
        cout<<"Erro na abertura do arquivo!"<<endl;
        return 0;
    }
    else
    {
        fprintf(pont_arq , " Classificacao do produto: %s\n" , c);
        fprintf(pont_arq , " UF do produtor: %c%c\n" , E[0] , E[1]);
        fprintf(pont_arq , " Municipio do lote: %s \n" , m);
        fprintf(pont_arq , " Nome do produtor: %s \n" , f);
        fprintf(pont_arq , " CNPJ do produtor: %d\n" , CNPJ);
        fprintf(pont_arq , " Validade do lote: %d / %d / %d\n" , D , MM , AA);
        
        fclose(pont_arq);

        cout<<"Dados gravados com sucesso!"<<endl;
        
        return 0;
    }
}


int main()
{

    //C = Classificação do produto;
    //F = Nome da fazenda
    //CNPJ = CNPJ da fazenda; 
    //M= Municipio de onde veio o lote;
    //Vetor E =  UF;
    //D= Dia
    //MM= Mês
    //AA= Ano;
    //S= espaço para formatação da data de validade 
    
    string  C , M , F;
    char E[2] , S[1];
    
    int  D, MM , AA , CNPJ;
    

    while(C != "Bovino" && C!="Suino" && C!="Ovino" && C!="Peixe")
    {
    
    cout<<"Escreva a classificacao do produto do lote(Bovino ou Suino ou  ou Ovino Peixe ):"<<endl;
    cin>>C;

    if(C != "Bovino" && C!="Suino" && C!="Ovino" && C!="Peixe")
    {
        cout<<"Classificao invalida"<<endl;
    }
    
    }

    cout<<"Digite a data de validade do lote com o formato 00/00/0000:"<<endl;
    cin>>D>>S[0]>>MM>>S[0]>>AA;

    while((D<1 || D>31) || (MM<1 || MM>12) || (AA<2023 || AA>2024))
    {
        cout<<"Data invalida - Digite uma data de validade com o formato 00/00/0000:"<<endl;
        cin>>D>>S[0]>>MM>>S[0]>>AA;
        
    }

    cout<<"Digite o nome do produtor do lote:"<<endl;
    cin>>F;

    cout<<"Digite o CNPJ do produtor(somente os digitos):"<<endl;
    cin>>CNPJ;

    cout<<"Insira a sigla UF onde o lote foi produzido(ex:GO , RJ , SP ):"<<endl;
    cin>>E[0]>>E[1];

    cout<<"Insira o Municipio onde o lote foi produzido:"<<endl;
    cin>>M;


    armazenamento(C , M , F , E , S , D , MM , AA , CNPJ);



    



}