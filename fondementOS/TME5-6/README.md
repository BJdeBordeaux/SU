# Rapport de TME5-6
### par LI Junji 28610187 && Mohamed BABAALI 28601465
<hr>

1. Tab1case
    1. Sémaphore SEM_NB_RECEPT (voir le code)
    1. Ce tableau assure qu'un Recepteur ne peut que prendre le même message une seule fois ; s'il y a qu'une seul sémaphore, il se peut que le même Recepteur fait V (tenter de décrementer le nb_recepteur plusieures fois). Sémaphore SEM_EMET previent les émetteurs de la disponibilité de la case.
    1. Voir le code.