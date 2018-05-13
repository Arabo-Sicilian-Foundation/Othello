# Othello
https://github.com/Arabo-Sicilian-Foundation/Othello

**[C][FR]** Projet de prgrammation impérative L2 Info

Jeu d'Othello (reversi) avec une ia.

1 à 2 joueurs.

## Téléchargement
`git clone https://github.com/Arabo-Sicilian-Foundation/Othello.git`

## Prérequis
- GCC

  `sudo apt-get install build-essential`
  
- MLV
  
  http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/download.html

## Compilation

  ### Prérequis :
  
    `sudo apt-get install make`
  
  ### Dans le dossier du jeu :
    
  - compilation :
  
    ### Pour compiler le jeu uniquement :  

    	make
    ou
	make reversi	

    ### Pour compiler le jeu et le fichier latex :

    	make all
	
## Lancement
    
    ./reversi -n x -p y

    où :
      
      -n: option obligatoire, indique le niveau de l'IA souhaité
      x: argument de l'option -n, valeur de 0 à 3
      
      -p: option non obligatoire, indique la profondeur de l'arbre pour les IA niveau 2 et 3
      y: argument de l'option -n, valeur minimale de 1
      	 la profondeur sera défini par défaut à 5 si l'option -p n'est pas utilisé
      
## Sources
- Documentation de la bibliothèque MLV-2.0.2 :

  http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/index.html
  
- Pour l'algorithme alpha-beta :

  http://lig-membres.imag.fr/pernet/Enseignements/L3METI_ProgOO/MinMaxAlphaBeta.pdf
