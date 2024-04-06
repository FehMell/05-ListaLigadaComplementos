#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = new NO;
	if (novo == nullptr) {
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = nullptr;

	if (primeiro == nullptr || primeiro->valor > novo->valor) {
		novo->prox = primeiro;
		primeiro = novo;
	}
	else if (primeiro->valor == novo->valor) {
		cout << "Elemento ja existe na lista.\n";
		delete novo;
		return;
	}
	else {
		NO* anterior = primeiro;
		NO* atual = primeiro->prox;
		while (atual != nullptr && atual->valor < novo->valor) {
			anterior = atual;
			atual = atual->prox;
		}
		if (atual != nullptr && atual->valor == novo->valor) {
			cout << "Elemento ja existe na lista.\n";
			delete novo;
			return;
		}
		anterior->prox = novo;
		novo->prox = atual;
	}
}

void excluirElemento()
{
	int numero;
	cout << "Digite o elemento a ser excluido: ";
	cin >> numero;

	NO* anterior = nullptr;
	NO* atual = primeiro;

	while (atual != nullptr && atual->valor < numero) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual != nullptr && atual->valor == numero) {
		if (anterior == nullptr) {
			primeiro = atual->prox;
		}
		else {
			anterior->prox = atual->prox;
		}
		delete atual;
		cout << "Elemento excluido com sucesso.\n";
	}
	else {
		cout << "Elemento nao encontrado na lista.\n";
	}
}
void buscarElemento() {
	int numero;
	cout << "Digite o elemento a ser buscado: ";
	cin >> numero;

	NO* aux = primeiro;
	while (aux != nullptr && aux->valor < numero) {
		aux = aux->prox;
	}

	if (aux != nullptr && aux->valor == numero) {
		cout << "Elemento encontrado na lista.\n";
	}
	else {
		cout << "Elemento nao encontrado na lista.\n";
	}
}


