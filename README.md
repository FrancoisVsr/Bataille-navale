# Bataille-navale
SEC1 Projet - bataille navale

Réalisé par Corentin GAUTHIER, François VASSEUR, Jonathan FAVE et Jean AUFFRAY
Ce projet fonctionne de façon optimal sur windows, il fonctionnera aussi sur LINUX. Il rentre dans le cadre de notre formation d'ingénieur à l'école Centrale de Nantes.

## Compilation windows
Pour compiler vous devez avoir intallé préalablement le compilateur g++.
Vous devez aussi avoir un outils de controle de génération d'éxécutable 
qui puisse lire les Makefile. De préférence mingw32-make.
Pour compiler rendez-vous dans le dossier build puis lancer la commande "mingw32-make all" 
ou "make all" en fonction de l'outil que vous avez. Après ça l'éxécutable est généré, vous pouvez le lancer.

## Compilation LINUX
Aucun script de compilation n'a été écrit pour compiler ce projet sous LINUX.
vous devez donc compiler les fichier contenu dans src/ à la main

## Documentation
Le document Doxyfile est présent pour générer la documentation html de notre projet. Pour l'utiliser, vérifiez que vous avez la version 1.9.4 de doxygen installée. Ensuite, lancez Doxywizard, allez chercher le fichier Doxyfile, rendez-vous ensuite dans l'onglet Run dans la partie gauche de Doxywizard et lancer doxygen (run doxygen). Les fichiers seront générés dans le dossier doc/. Pour visualiser le résultat, ouvrez l'index dans un navigateur.