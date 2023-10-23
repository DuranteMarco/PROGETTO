#include <stdio.h>
#include <stdbool.h>

// Definizione della struttura della tessera del domino
typedef struct {
    int left;
    int right;
} Tile;

// Funzione per stampare una tessera
void printTile(Tile tile) {
    printf("[%d|%d] ", tile.left, tile.right);
}

// Funzione per verificare se è possibile giocare una tessera sulla tavola
bool canPlay(Tile board[], Tile tile, int size) {
    if (size == 0) {
        return true; // La prima tessera può essere giocata ovunque
    }

    if (board[size - 1].right == tile.left) {
        return true; // La tessera può essere giocata a destra
    }

    if (board[0].left == tile.right) {
        return true; // La tessera può essere giocata a sinistra
    }

    return false;
}

int main() {
    Tile board[100]; // Array per memorizzare le tessere giocate
    int boardSize = 0; // Numero di tessere sulla tavola
    int playerScore = 0; // Punteggio del giocatore

    // Esempio di tessere assegnate al giocatore
    Tile playerTiles[] = {{6, 6}, {6, 6}, {6, 6}, {3, 6}, {1, 6}, {2, 6}, {1, 4}, {3, 4}, {4, 4}, {4, 5}};
    int numTiles = sizeof(playerTiles) / sizeof(Tile);

    // Ciclo del gioco
    while (numTiles > 0) {
        // Stampa la tavola e le tessere del giocatore
        printf("Tavola: ");
        for (int i = 0; i < boardSize; ++i) {
            printTile(board[i]);
        }
        printf("\n");

        printf("Tessere del giocatore: ");
        for (int i = 0; i < numTiles; ++i) {
            printTile(playerTiles[i]);
        }
        printf("\n");

        // Chiede all'utente di giocare una tessera
        int choice;
        printf("Scegli una tessera da giocare (0-%d): ", numTiles - 1);
        scanf("%d", &choice);

        // Verifica se la mossa è valida e aggiorna il punteggio
        if (canPlay(board, playerTiles[choice], boardSize)) {
            Tile playedTile = playerTiles[choice];
            // Rimuove la tessera giocata dalla mano del giocatore
            for (int i = choice; i < numTiles - 1; ++i) {
                playerTiles[i] = playerTiles[i + 1];
            }
            numTiles--;

            // Aggiunge la tessera alla tavola e calcola il punteggio
            board[boardSize] = playedTile;
            boardSize++;

            // Aggiorna il punteggio
            playerScore += playedTile.left + playedTile.right;
        } else {
            printf("Mossa non valida!\n");
        }
    }

    // Stampa il punteggio finale
    printf("Gioco terminato. Punteggio finale: %d\n", playerScore);

    return 0;
}
