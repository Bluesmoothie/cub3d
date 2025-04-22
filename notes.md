## Taches
Parsing map : simon
Initialisation (chargement texture, free a la fin) : yves
Gestion inputs (clavier souris) : yves
Render :

## Bonus
Collisions : yves
Minicarte : 
Portes : 
Animations :
Controle pdv a la souris :

## ex struct

## Ray casting

Implique une camera parallele au sol

La camera projette un rayon par pixel, la collision la plus proche de la camera defini la couleur du pixel
- >regrouper les pixel par multiple de 4 pour accelerer le rendu/baisser la qualite
- >envoyer un rayon par pixel en largeur suffit pour definir ce qu'on vois sur toute la longueur
- >la distance de collision defini la taille du mur, remplir le reste avec le sol et plafond

Un point de fuite

## controles

<- -> rotation camera
WASD deplacement
ESC X quitter