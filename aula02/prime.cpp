#include <cassert>
#include <iostream>
#include <string>  // Necessário para trabalhar com std::string

using namespace std;


// Usar como base os prototipos
// de LinkedList vistos em aula

// =================================================================
// Classe Stack: implementa o Terminal 0 utilizando uma pilha (LIFO)
// =================================================================
class Stack
{
public:
    // Construtor: inicializa a pilha como vazia
    Stack() : top(nullptr), count(0) {}
    // Destrutor: libera a memória alocada (usa clear para remover todos os nós)
    ~Stack() { clear(); }
    
    // ADD CODE HERE: Declaração dos métodos públicos da classe
    void push(int value);   // Insere um valor no topo da pilha
    int pop();              // Remove e retorna o valor do topo da pilha
    bool isEmpty() const;   // Retorna true se a pilha estiver vazia
    int size() const;       // Retorna o número de elementos na pilha
    void clear();           // Remove todos os elementos da pilha
    
private:
    // ADD CODE HERE: Definição da estrutura de nó e variáveis membros
    struct Node {
        int data;         // Armazena o número do vagão
        Node* next;       // Ponteiro para o próximo nó na pilha
        Node(int d) : data(d), next(nullptr) {}  // Construtor do nó
    };
    Node* top;            // Ponteiro para o nó do topo da pilha
    int count;            // Contador de elementos na pilha
};

// ADD Stack METHODS DEFINITIONS HERE

// Insere um novo nó no topo da pilha
void Stack::push(int value) {
    Node* newNode = new Node(value);  // Cria um novo nó com o valor
    newNode->next = top;              // Faz o novo nó apontar para o antigo topo
    top = newNode;                    // Atualiza o topo para o novo nó
    count++;                          // Incrementa o contador
}

// Remove o nó do topo e retorna seu valor
int Stack::pop() {
    assert(!isEmpty());               // Garante que a pilha não esteja vazia
    Node* temp = top;                 // Armazena o nó a ser removido
    int value = temp->data;           // Guarda o valor do nó
    top = top->next;                  // Atualiza o topo para o próximo nó
    delete temp;                      // Libera a memória do nó removido
    count--;                          // Decrementa o contador
    return value;                     // Retorna o valor removido
}

// Retorna true se a pilha estiver vazia
bool Stack::isEmpty() const {
    return top == nullptr;
}

// Retorna a quantidade de elementos na pilha
int Stack::size() const {
    return count;
}

// Remove todos os elementos da pilha
void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

// =================================================================
// Classe Deque: implementa o Terminal 1 utilizando um deque (fila dupla)
// =================================================================
class Deque
{
public:
    // Construtor: inicializa o deque como vazio
    Deque() : left(nullptr), right(nullptr), count(0) {}
    // Destrutor: libera a memória alocada (usa clear para remover todos os nós)
    ~Deque() { clear(); }
    
    // ADD CODE HERE: Declaração dos métodos públicos da classe
    void insertLeft(int value);   // Insere um valor à esquerda do deque
    void insertRight(int value);  // Insere um valor à direita do deque
    int removeLeft();             // Remove e retorna o valor da esquerda
    int removeRight();            // Remove e retorna o valor da direita
    bool isEmpty() const;         // Retorna true se o deque estiver vazio
    int size() const;             // Retorna a quantidade de elementos no deque
    void clear();                 // Remove todos os elementos do deque
    
private:
    // ADD CODE HERE: Definição da estrutura de nó e variáveis membros
    struct Node {
        int data;         // Armazena o número do vagão
        Node* prev;       // Ponteiro para o nó anterior
        Node* next;       // Ponteiro para o próximo nó
        Node(int d) : data(d), prev(nullptr), next(nullptr) {}  // Construtor do nó
    };
    Node* left;           // Ponteiro para a extremidade esquerda do deque
    Node* right;          // Ponteiro para a extremidade direita do deque
    int count;            // Contador de elementos no deque
};

// ADD Deque METHODS DEFINITIONS HERE

// Insere um novo nó à esquerda do deque
void Deque::insertLeft(int value) {
    Node* newNode = new Node(value);  // Cria um novo nó com o valor
    if (isEmpty()) {
        // Se o deque está vazio, o novo nó é as duas extremidades
        left = right = newNode;
    } else {
        newNode->next = left;         // O novo nó aponta para o atual left
        left->prev = newNode;         // O antigo left aponta de volta para o novo nó
        left = newNode;               // Atualiza a extremidade esquerda
    }
    count++;                          // Incrementa o contador
}

// Insere um novo nó à direita do deque
void Deque::insertRight(int value) {
    Node* newNode = new Node(value);  // Cria um novo nó com o valor
    if (isEmpty()) {
        // Se o deque está vazio, o novo nó é as duas extremidades
        left = right = newNode;
    } else {
        newNode->prev = right;        // O novo nó aponta para o atual right
        right->next = newNode;        // O antigo right aponta para o novo nó
        right = newNode;              // Atualiza a extremidade direita
    }
    count++;                          // Incrementa o contador
}

// Remove o nó da esquerda e retorna seu valor
int Deque::removeLeft() {
    assert(!isEmpty());               // Garante que o deque não esteja vazio
    Node* temp = left;                // Armazena o nó a ser removido
    int value = temp->data;           // Guarda o valor do nó
    left = left->next;                // Atualiza a extremidade esquerda
    if (left != nullptr)
        left->prev = nullptr;         // Remove a referência do novo left ao antigo
    else
        right = nullptr;              // Se ficou vazio, atualiza a extremidade direita
    delete temp;                      // Libera a memória do nó removido
    count--;                          // Decrementa o contador
    return value;                     // Retorna o valor removido
}

// Remove o nó da direita e retorna seu valor
int Deque::removeRight() {
    assert(!isEmpty());               // Garante que o deque não esteja vazio
    Node* temp = right;               // Armazena o nó a ser removido
    int value = temp->data;           // Guarda o valor do nó
    right = right->prev;              // Atualiza a extremidade direita
    if (right != nullptr)
        right->next = nullptr;        // Remove a referência do novo right ao antigo
    else
        left = nullptr;               // Se ficou vazio, atualiza a extremidade esquerda
    delete temp;                      // Libera a memória do nó removido
    count--;                          // Decrementa o contador
    return value;                     // Retorna o valor removido
}

// Retorna true se o deque estiver vazio
bool Deque::isEmpty() const {
    return left == nullptr;
}

// Retorna a quantidade de elementos no deque
int Deque::size() const {
    return count;
}

// Remove todos os elementos do deque
void Deque::clear() {
    while (!isEmpty()) {
        removeLeft();
    }
}


// =================================================================
// Função principal: lê e processa as operações de entrada e saída
// =================================================================
int main()
{
    string op;         // Variável para armazenar a operação lida
    int next_car = 0;  // Contador para o número do próximo vagão (inicia em 0)
    Stack t0;          // Terminal 0 (pilha)
    Deque t1;          // Terminal 1 (deque)
    
    while (true) {
        cin >> op;     // Lê a operação
        if (cin.eof()) break;  // Encerra se chegar ao fim do arquivo
        
        // ADD MAIN LOOP CODE HERE
        if(op == "FIM") {
            // Ao fim do caso, imprime:
            // 1. O número de vagões restantes no Terminal 0
            // 2. O número de vagões restantes no Terminal 1
            // 3. Uma linha em branco para separar os casos
            cout << t0.size() << "\n";
            cout << t1.size() << "\n\n";
            
            // Reinicia os terminais e o contador para um novo caso
            t0.clear();
            t1.clear();
            next_car = 0;
        }
        else if(op == "E0") {
            // E0: entrada de vagão no Terminal 0 (pilha)
            t0.push(next_car);
            next_car++;
        }
        else if(op == "S0") {
            // S0: saída do Terminal 0; se houver vagão, remove e imprime seu número
            if(!t0.isEmpty())
                cout << t0.pop() << "\n";
        }
        else if(op == "E1E") {
            // E1E: entrada de vagão no Terminal 1 pela esquerda
            t1.insertLeft(next_car);
            next_car++;
        }
        else if(op == "E1D") {
            // E1D: entrada de vagão no Terminal 1 pela direita
            t1.insertRight(next_car);
            next_car++;
        }
        else if(op == "S1E") {
            // S1E: saída do Terminal 1 pela esquerda; se houver vagão, remove e imprime seu número
            if(!t1.isEmpty())
                cout << t1.removeLeft() << "\n";
        }
        else if(op == "S1D") {
            // S1D: saída do Terminal 1 pela direita; se houver vagão, remove e imprime seu número
            if(!t1.isEmpty())
                cout << t1.removeRight() << "\n";
        }
    }
    return 0;
}
