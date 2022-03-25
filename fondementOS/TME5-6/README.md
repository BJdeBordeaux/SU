# Rapport de TME5-6
### par LI Junji 28610187 && Mohamed BABAALI 28601465
<hr>

1. Tab1case
    1. Sémaphore SEM_NB_RECEPT (voir le code)
    1. Ce tableau assure qu'un Recepteur ne peut que prendre le même message une seule fois ; s'il y a qu'une seul sémaphore, il se peut que le même Recepteur fait V (tenter de décrementer le nb_recepteur plusieures fois). Sémaphore SEM_EMET previent les émetteurs de la disponibilité de la case.
    1. Voir le code.
1. TabNcase
    1. 
        1. Variables (valeur initiale): `indexEcrireCase (0)` pour la case qu'on va écrire le message, `nb_recepteurs[NMAX] (0)` pour compter combien de récepteur a reçu le message de cette case, `caseContenu[NMAX] (-1)` pour le contenu d'une case.
        1. Sémaphores (valeur initiale): `S_EMETTEUR (NMAX)`  pour limiter droit d'écriture, `S_IndexEcrireCase (1)` pour progéger `indexEcrireCase`, `S_NbRecption (1)` pour protéger `nb_recepteurs[NMAX]`, `S_CASES[NMAX] (1)` pour protéger `caseContenu[NMAX]`, `S_RECEPTEUR[NR] (0)` pour éviter un récepteur de recevoir une case non écrite. (voir le code)
    1.  côté récepteur:
        ```python3
            P(S_RECEPTEUR[id_recp]) # demander le droit de lecture
            P(S_CASES[caseALire]) # monopoliser la case à lire
                lire(caseALire) # lire la case
            V(S_CASES[caseALire]) # libérer ce monopole
            P(S_NbRecption) # protéger la variable
            sp->nb_recepteurs[caseALire] += 1 # enregistrer cette lecture
                    if sp->nb_recepteurs[caseALire] == NR: # si tous les récepteurs ont lu la case
                            sp->nb_recepteurs[caseALire] = 0 # réinitialise le compteur
                            V(S_EMETTEUR) # et ouvrir le droit pour écrire dans cette case
            V(S_NbRecption) # terminer la protection pour le compteur
            caseALire = (caseALire + 1) % NMAX # déplacer vers la prochaine case à lire
        ```
        côté emetteur:
        ```python3
            P(S_IndexEcrireCase) # protéger l'indice
                int tmp = sp->indexEcrireCase # noter cette indice
                sp->indexEcrireCase = (sp->indexEcrireCase+1) % NMAX # déplacer cette indice vers la prochaine case
            V(S_IndexEcrireCase) # libérer la protection
            P(S_EMETTEUR) # demander le droit d'écriture
            P(S_CASES[tmp]) # protéger le contenu de la case
                ecrire(tmp) # écrire dans la case
            V(S_CASES[tmp]); # libérer la protection
            for (int i = 0; i < NR; i++): # pour chaque récepteur
                V(S_RECEPTEUR[i]) # on lui offre droit de lecture (une seule fois)
        ```
    1. voir le code