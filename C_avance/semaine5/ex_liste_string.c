#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_string.h"

int main(void) {

  /* a completer. Exercice 5, question 2 */
  PListe pliste = malloc(sizeof(Liste));
  pliste->afficher = afficher_str;
  pliste->comparer = comparer_str;
  pliste->copier = copier_str;
  pliste->detruire = detruire_str;
  pliste->dupliquer = dupliquer_str;
  pliste->lire = lire_str;

  FILE *f;
  char* str;

  char* str2 = "Hola mundo!\n";
  // Si on met str2 au lieu de &str2, il n'affiche qu'un char
  char* str3 = (char*) dupliquer_str(&str2);
  assert(strcmp(str2, str3) == 0);

  f = fopen("string_entree.txt", "r");
  str = strdup((char*) lire_str(f));
  fclose(f);
  afficher_str(str);
  newLigne();

  assert(comparer_str("a","b")<0);
  assert(comparer_str("Hello!","Hello!") == 0);

  copier_str(&str, &str3);
  assert(strcmp(str, str3) == 0);

  f = fopen("string_sortie.txt", "w");

  ecrire_str(&str, f);
  fclose(f);

  detruire_liste(pliste);
  free(str);
  // free(str2);
  free(str3);
  return 0;
}
