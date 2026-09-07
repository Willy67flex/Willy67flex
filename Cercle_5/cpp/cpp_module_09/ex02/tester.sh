#!/bin/bash

# Couleurs pour l'affichage
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

printf "${BLUE}=== Lancement des tests PmergeMe ===${NC}\n\n"

# Fonction pour vérifier si une liste est triée
check_sorted() {
    local output=$1
    # On extrait la ligne qui commence par "After" et on récupère les nombres
    local sorted_list=$(echo "$output" | grep "After" | sed 's/After : //')
    local expected_list=$(echo $sorted_list | tr ' ' '\n' | sort -n | tr '\n' ' ')
    
    # Nettoyage des espaces en trop
    sorted_list=$(echo $sorted_list | xargs)
    expected_list=$(echo $expected_list | xargs)

    if [ "$sorted_list" == "$expected_list" ]; then
        return 0 # OK
    else
        return 1 # ERROR
    fi
}

# 1. TESTS DE PARSING (ERREURS)
printf "${YELLOW}1. Tests de Parsing (doivent afficher Error)${NC}\n"
tests_error=(" -1 2 3" "1 a 3" "1.2 3" "2147483648" "" "++3 4")

for arg in "${tests_error[@]}"; do
    printf "Test [./PmergeMe $arg] : "
    result=$(./PmergeMe $arg 2>&1)
    if [[ "$result" == *"Error"* ]]; then
        printf "${GREEN}OK (Error detected)${NC}\n"
    else
        printf "${RED}KO (No Error detected)${NC}\n"
    fi
done

# 2. TESTS DE VALIDITÉ DU TRI
printf "\n${YELLOW}2. Tests de validité du tri${NC}\n"
tests_valid=("3 5 9 7 4" "1 2 3" "10 9 8 7 6 5 4 3 2 1" "42 42 42" "+5 0 10" "100 1 50 2 25")

for arg in "${tests_valid[@]}"; do
    printf "Test [./PmergeMe $arg] : "
    output=$(./PmergeMe $arg)
    if check_sorted "$output"; then
        printf "${GREEN}OK (Sorted)${NC}\n"
    else
        printf "${RED}KO (Not Sorted)${NC}\n"
        echo "Output: $output"
    fi
done

# 3. TEST DE PERFORMANCE ET STATISTIQUES (3000 ÉLÉMENTS)
printf "\n${YELLOW}3. Test de performance (3000 éléments, 20 itérations)${NC}\n"

ITERATIONS=20
NB_ELEMENTS=3000
VECTOR_TIMES=()
DEQUE_TIMES=()

for ((i=1; i<=ITERATIONS; i++)); do
    # Génération d'une liste aléatoire
    ARG=$(shuf -i 1-100000 -n $NB_ELEMENTS | tr "\n" " ")
    OUTPUT=$(./PmergeMe $ARG)
    
    # Extraction des temps (on enlève " us" et on récupère le chiffre)
    V_TIME=$(echo "$OUTPUT" | grep "vector" | awk '{print $(NF-1)}')
    D_TIME=$(echo "$OUTPUT" | grep "deque" | awk '{print $(NF-1)}')
    
    VECTOR_TIMES+=($V_TIME)
    DEQUE_TIMES+=($D_TIME)
    
    # Vérification rapide du tri sur le premier test pour être sûr
    if [ $i -eq 1 ]; then
        if check_sorted "$OUTPUT"; then
            printf "Tri validé pour 3000 éléments. Calcul des stats en cours...\n"
        else
            printf "${RED}KO : Le tri de 3000 éléments a échoué !${NC}\n"
            exit 1
        fi
    fi
    printf "."
done
printf "\n"

# Calcul des statistiques
calc_stats() {
    local name=$1
    shift
    local times=("$@")
    
    local min=${times[0]}
    local max=${times[0]}
    local sum=0
    
    for t in "${times[@]}"; do
        if (( $(echo "$t < $min" | bc -l) )); then min=$t; fi
        if (( $(echo "$t > $max" | bc -l) )); then max=$t; fi
        sum=$(echo "$sum + $t" | bc -l)
    done
    
    local avg=$(echo "$sum / $ITERATIONS" | bc -l)
    
    printf "${BLUE}Stats pour $name :${NC}\n"
    printf "  - Moyenne : $(printf "%.2f" $avg) us\n"
    printf "  - Plus rapide : $min us\n"
    printf "  - Plus lent   : $max us\n"
}

calc_stats "std::vector" "${VECTOR_TIMES[@]}"
calc_stats "std::deque " "${DEQUE_TIMES[@]}"

printf "\n${GREEN}=== Tests terminés ===${NC}\n"