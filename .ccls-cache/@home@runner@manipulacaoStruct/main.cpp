/*
Titulo: Manipulação Struct
Autor: Yuri Brollo
Data: 2024.10.11*/

// Espaço reservado para declaração de bibliotecas
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std; 

//Construção da Struct 
struct Pessoa{
  int codigo;
  string nome;
  float altura;
};

// Prototipação de funções
int menu();
int lerCodigoValido(const string  &mensagem);
void limpaBuffer();
void exibirMsgErro(const string &mensagem);
void mostrarArray(Pessoa array[], int tamanho); 
void esperarEnter();
void zerarArray(Pessoa array[], int tamanho);
void preencherArray(Pessoa array[], int tamanho);
string lerStringValida(const string &mensagem);
float lerAlturaValida(const string &mensagem);
void ordenarArray(Pessoa array[], int tamanho);
void verificarPessoa(Pessoa array[], int tamanho);
void editarArray(Pessoa array[], int tamanho);



//Função principal
int main()
{ 
  const int TAMANHO = 5; // Define o tamanho do Array de pessoas
  Pessoa array[TAMANHO]; // declara o array para armazenar TAMANHO registros de pessoas
  int opcao = 0; //Declara a váriavel para armazenar a opção do usuário

  do{
    opcao = menu();
    switch(opcao){
      case 1: mostrarArray(array, TAMANHO); break;
      case 2: zerarArray(array, TAMANHO); break;
      case 3: preencherArray(array, TAMANHO); break;
      case 4: editarArray(array, TAMANHO); break;
      case 5: verificarPessoa(array, TAMANHO); break;
      case 6: ordenarArray(array, TAMANHO); break;
      case 0: cout << "Encerrar Programa" <<endl; break;
      default: exibirMsgErro("Opcão Inválida! Escolha uma Opção Válida."); break;
    }
  } while(opcao != 0);

  return 0;

}


// Função que exibe o menu e retorna a escolha do usuário
int menu()
{
  cout << "\nEscolha uma opção: \n";
  cout << "1 - mostrar array de pessoas\n";
  cout << "2 - Zerar array de pessoas";
  cout << "Preencher array de pessoas\n";
  cout << "4 - Editar pessoa no array\n";
  cout << "5 - Verificar pessoa no array\n";
  cout << "6 - Ordenar array de pessoas por código\n";
  cout << "0 - Sair\n";
  return lerCodigoValido("Opção: ");
  
}

int lerCodigoValido(const string  &mensagem){
  int numero;
  while(true){
    cout << mensagem;
    cin >> numero;
    if (cin.fail()){
      limpaBuffer();
      exibirMsgErro("Entrada Inválida! Por favor insira um número inteiro:");
    } else {
      limpaBuffer();
      return numero;
    }
  }
}

// Função para limpar o buffer de entrada
void limpaBuffer(){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora entradas inválidas no buffer 
}

// Função para exibir mensagem de Erro
void exibirMsgErro(const string &mensagem)
{
  cout << mensagem << endl;
}

// Função para mostar o Array de Pessoas

void mostrarArray(Pessoa array[], int tamanho)
{
  cout << left << setw(10)<<"Código"<<"\t" << left << setw(20) << "Nome" << "\t" << left << setw(10) << "Altura" << endl;
  cout << string(50, '-') << endl;
  for(int i =0; i <tamanho; i++)
  {
    cout << left << setw(10)<<array[i].codigo <<"\t" << left << setw(20) << array[i].nome << left << setw(10) << array[i].altura << endl;   
  }
  esperarEnter();
  
}

void esperarEnter()
{
  cout << "\nPressione Enter";
  cin.get();
}

void zerarArray(Pessoa array[], int tamanho)
{
  for (int i=0; i<tamanho; i++)
    {
      array[i].codigo = 0;
      array[i].nome = "";
      array[i].altura = 0.0;
    }
  
  cout << "Array de pessoas zerado!";
  esperarEnter();
}

void preencherArray(Pessoa array[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
    {
      array[i].codigo = lerCodigoValido("Digite o codigo da pessoa ["+to_string(i)+"]: ");
      array[i].nome = lerStringValida("Digite o nome da pessoa ["+to_string(i)+"]: ");
      array[i].altura = lerAlturaValida("Digite a altura da pessoa ["+to_string(i)+"]: ");
      cout << "Array de pessoas preenchido com sucesso";
    }
  esperarEnter();
}
string lerStringValida(const string &mensagem)
{
  string entrada;
  cout << mensagem;
  getline(cin, entrada);
  return entrada;
}

float lerAlturaValida(const string &mensagem)
{
  float altura;
  while(true)
    {
      cout << mensagem;
      cin >> altura;
      if (cin.fail() || altura <= 0)
      {
        limpaBuffer();
        exibirMsgErro("entrada invalida");
      } 
      else
      {
       limpaBuffer();
        return altura;
      }
    }
}

void editarArray(Pessoa array[], int tamanho)
{
  int posicao = lerCodigoValido("Digite a posição (0 a "+to_string(tamanho-1)+"): ");
  while (posicao < 0 || posicao >= tamanho)
    {
      exibirMsgErro("Posição Invalida");
      posicao = lerCodigoValido("Digite a posição: ");
    }
  array[posicao].codigo = lerCodigoValido("Digite o novo código para ["+to_string(posicao)+"]: ");
  limpaBuffer();
  array[posicao].nome = lerStringValida("Digite o nome da pessoa ["+to_string(posicao)+"]: ");
  array[posicao].altura = lerAlturaValida("Digite a altura da pessoa ["+to_string(posicao)+"]: ");
  cout << "Array de pessoas preenchido com sucesso";
  esperarEnter();
  
}

void verificarPessoa(Pessoa array[], int tamanho)
{
  int codigo = lerCodigoValido("Numero da pessoa que deseja vereficar");
  bool encontrado = false;
  for (int i = 0; i<tamanho; i++)
    {
      if(array[i].codigo == codigo)
      {
        cout << "Pessoa com o Código " << codigo << " encontrada" << endl;
        cout << "Nome " << array[i].nome << endl;
        cout << "Altura " << array[i].altura << endl;
        encontrado = true;
        break;
      }
    }
    if(!encontrado)
    {
      cout << "Pessoa com o código " << codigo << " não encontrada" << endl;
    }
  esperarEnter();
}

void ordenarArray(Pessoa array[], int tamanho)
{
  sort(array, array+tamanho, [](Pessoa a, Pessoa b)
  {
    return a.codigo < b.codigo;
    
  });
  cout << "Array de pessoas ordenadas por código";
  esperarEnter();
}
