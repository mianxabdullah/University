import random
import math

items = [
    (2, 12), (1, 10), (3, 20), (2, 15), (4, 25),
    (5, 30), (7, 42), (6, 35), (3, 18), (2, 14),
    (8, 50), (9, 55), (4, 24), (5, 28), (1, 8),
    (6, 33), (7, 40), (3, 16), (2, 11), (4, 22),
    (10, 60), (9, 52), (5, 29), (6, 34), (2, 13),
    (1, 7), (8, 48), (7, 39), (3, 19), (4, 23)
]
MAX_WEIGHT = 60
POPULATION_SIZE = 30
MUTATION_RATE = 0.05
GENERATIONS = 50
TOURNAMENT_SIZE = 3

def get_user_input():
    print("\n--- KNAPSACK PROBLEM SETUP ---")
    choice = input("Use default dataset? (y/n): ").strip().lower()
    
    if choice == 'y':
        num_items = len(items)
        max_weight = MAX_WEIGHT
        items_list = items
    else:
        try:
            num_items = int(input("Enter number of items: "))
            items_list = []
            for i in range(num_items):
                weight = int(input(f"Enter weight of item {i+1}: "))
                value = int(input(f"Enter value of item {i+1}: "))
                items_list.append((weight, value))
            max_weight = int(input("Enter knapsack capacity: "))
        except ValueError:
            print("Invalid input. Using default dataset.")
            items_list = items
            max_weight = MAX_WEIGHT
    
    return items_list, max_weight

def initialize_population(size, num_items):
    population = []
    for _ in range(size):
        chromosome = [random.randint(0, 1) for _ in range(num_items)]
        population.append(chromosome)
    return population

def fitness(chromosome, items, max_weight):
    total_weight = 0
    total_value = 0
    
    for i, gene in enumerate(chromosome):
        if gene == 1:
            total_weight += items[i][0]
            total_value += items[i][1]
    
    if total_weight > max_weight:
        return 0
    return total_value

def calculate_weight(chromosome, items):
    total_weight = 0
    for i, gene in enumerate(chromosome):
        if gene == 1:
            total_weight += items[i][0]
    return total_weight

def roulette_wheel_selection(population, items, max_weight):
    fitnesses = [fitness(chromosome, items, max_weight) for chromosome in population]
    total_fitness = sum(fitnesses)
    
    if total_fitness == 0:
        return random.choice(population)
    
    # Calculate selection probabilities
    probabilities = [f / total_fitness for f in fitnesses]
    
    # Roulette wheel selection
    r = random.random()
    cumulative_prob = 0
    for i, prob in enumerate(probabilities):
        cumulative_prob += prob
        if r <= cumulative_prob:
            return population[i]
    
    return population[-1]

def tournament_selection(population, items, max_weight, k=3):
    tournament = random.sample(population, min(k, len(population)))
    best = max(tournament, key=lambda x: fitness(x, items, max_weight))
    return best

def select_parent(population, items, max_weight, method):
    if method == "roulette":
        return roulette_wheel_selection(population, items, max_weight)
    elif method == "tournament":
        return tournament_selection(population, items, max_weight, TOURNAMENT_SIZE)
    else:
        return roulette_wheel_selection(population, items, max_weight)

def crossover(parent1, parent2):
    if len(parent1) == 0:
        return parent1, parent2
    
    crossover_point = random.randint(1, len(parent1) - 1)
    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]
    return child1, child2

def mutate(chromosome, mutation_rate):
    mutated = chromosome.copy()
    for i in range(len(mutated)):
        if random.random() < mutation_rate:
            mutated[i] = 1 - mutated[i]  # Flip the gene
    return mutated

def genetic_algorithm(items, max_weight, selection_method):
    num_items = len(items)
    population = initialize_population(POPULATION_SIZE, num_items)
    best_solution = None
    best_fitness = 0
    
    print(f"\nRunning GA with {selection_method} selection...")
    print(f"Generation | Best Fitness")
    
    for generation in range(GENERATIONS):
        fitnesses = [fitness(chromosome, items, max_weight) for chromosome in population]
        
        current_best_idx = fitnesses.index(max(fitnesses))
        current_best_fitness = fitnesses[current_best_idx]
        
        if current_best_fitness > best_fitness:
            best_fitness = current_best_fitness
            best_solution = population[current_best_idx].copy()
        
        if generation % 10 == 0 or generation == GENERATIONS - 1:
            print(f"{generation:10d} | {best_fitness:12.0f}")
        
        new_population = []
        
        while len(new_population) < POPULATION_SIZE:
            parent1 = select_parent(population, items, max_weight, selection_method)
            parent2 = select_parent(population, items, max_weight, selection_method)
            
            child1, child2 = crossover(parent1, parent2)
            child1 = mutate(child1, MUTATION_RATE)
            child2 = mutate(child2, MUTATION_RATE)
            
            new_population.append(child1)
            if len(new_population) < POPULATION_SIZE:
                new_population.append(child2)
        
        population = new_population
    
    return best_solution, best_fitness

def display_solution(solution, items, max_weight, selection_method):
    total_weight = 0
    total_value = 0
    selected_items = []
    
    print("\n--- KNAPSACK SOLUTION ---")
    print(f"Selection Method: {selection_method}")
    print(f"Best Chromosome: {solution}")
    
    for i, gene in enumerate(solution):
        if gene == 1:
            total_weight += items[i][0]
            total_value += items[i][1]
            selected_items.append(i)
    
    print(f"Selected Items (indices): {selected_items}")
    print(f"Total Weight: {total_weight} / {max_weight}")
    print(f"Total Value: {total_value}")
    print(f"Fitness: {total_value}")

cities = {
    0: (2, 3),
    1: (5, 4),
    2: (1, 7),
    3: (6, 8),
    4: (9, 2),
    5: (4, 6),
    6: (8, 7),
    7: (3, 9)
}

TSP_POPULATION_SIZE = 30
TSP_GENERATIONS = 100
TSP_MUTATION_RATE = 0.05
TSP_TOURNAMENT_SIZE = 3

def get_tsp_input():
    print("\n--- TSP SETUP ---")
    choice = input("Use default cities? (y/n): ").strip().lower()
    
    if choice == 'y':
        cities_dict = cities
    else:
        try:
            num_cities = int(input("Enter number of cities: "))
            cities_dict = {}
            for i in range(num_cities):
                x = float(input(f"Enter x-coordinate of city {i}: "))
                y = float(input(f"Enter y-coordinate of city {i}: "))
                cities_dict[i] = (x, y)
        except ValueError:
            print("Invalid input. Using default cities.")
            cities_dict = cities
    
    return cities_dict

def distance(city1, city2):
    return math.sqrt((city1[0] - city2[0])**2 + (city1[1] - city2[1])**2)

def total_distance(route, cities):
    total = 0
    for i in range(len(route)):
        current_city = cities[route[i]]
        next_city = cities[route[(i + 1) % len(route)]]
        total += distance(current_city, next_city)
    return total

def tsp_fitness(route, cities):
    dist = total_distance(route, cities)
    if dist == 0:
        return float('inf')
    return 1.0 / dist

def initialize_tsp_population(size, num_cities):
    population = []
    for _ in range(size):
        route = list(range(num_cities))
        random.shuffle(route)
        population.append(route)
    return population

def tsp_roulette_wheel_selection(population, cities):
    fitnesses = [tsp_fitness(route, cities) for route in population]
    total_fitness = sum(fitnesses)
    
    if total_fitness == 0:
        return random.choice(population)
    
    probabilities = [f / total_fitness for f in fitnesses]
    
    r = random.random()
    cumulative_prob = 0
    for i, prob in enumerate(probabilities):
        cumulative_prob += prob
        if r <= cumulative_prob:
            return population[i]
    
    return population[-1]

def tsp_tournament_selection(population, cities, k=3):
    tournament = random.sample(population, min(k, len(population)))
    best = max(tournament, key=lambda x: tsp_fitness(x, cities))
    return best

def tsp_select_parent(population, cities, method):
    if method == "roulette":
        return tsp_roulette_wheel_selection(population, cities)
    elif method == "tournament":
        return tsp_tournament_selection(population, cities, TSP_TOURNAMENT_SIZE)
    else:
        return tsp_roulette_wheel_selection(population, cities)

def tsp_crossover(parent1, parent2):
    n = len(parent1)
    
    # Select two random crossover points
    point1 = random.randint(0, n - 1)
    point2 = random.randint(0, n - 1)
    
    if point1 > point2:
        point1, point2 = point2, point1
    
    # Create child1
    child1 = [-1] * n
    child1[point1:point2] = parent1[point1:point2]
    
    # Fill remaining positions from parent2
    idx = point2
    for city in parent2:
        if city not in child1:
            if idx >= n:
                idx = 0
            child1[idx] = city
            idx += 1
    
    # Create child2 similarly
    child2 = [-1] * n
    child2[point1:point2] = parent2[point1:point2]
    
    idx = point2
    for city in parent1:
        if city not in child2:
            if idx >= n:
                idx = 0
            child2[idx] = city
            idx += 1
    
    return child1, child2

def tsp_mutate(route, mutation_rate):
    mutated = route.copy()
    for _ in range(len(mutated)):
        if random.random() < mutation_rate:
            i = random.randint(0, len(mutated) - 1)
            j = random.randint(0, len(mutated) - 1)
            mutated[i], mutated[j] = mutated[j], mutated[i]
    return mutated

def tsp_genetic_algorithm(cities, selection_method):
    num_cities = len(cities)
    population = initialize_tsp_population(TSP_POPULATION_SIZE, num_cities)
    best_route = None
    best_distance = float('inf')
    
    print(f"\nRunning TSP GA with {selection_method} selection...")
    print(f"Generation | Best Distance | Best Fitness")
    
    for generation in range(TSP_GENERATIONS):
        fitnesses = [tsp_fitness(route, cities) for route in population]
        distances = [total_distance(route, cities) for route in population]
        
        best_idx = distances.index(min(distances))
        current_best_distance = distances[best_idx]
        
        if current_best_distance < best_distance:
            best_distance = current_best_distance
            best_route = population[best_idx].copy()
        
        if generation % 10 == 0 or generation == TSP_GENERATIONS - 1:
            print(f"{generation:10d} | {best_distance:13.4f} | {1/best_distance:.6f}")
        
        new_population = []
        
        while len(new_population) < TSP_POPULATION_SIZE:
            parent1 = tsp_select_parent(population, cities, selection_method)
            parent2 = tsp_select_parent(population, cities, selection_method)
            
            child1, child2 = tsp_crossover(parent1, parent2)
            child1 = tsp_mutate(child1, TSP_MUTATION_RATE)
            child2 = tsp_mutate(child2, TSP_MUTATION_RATE)
            
            new_population.append(child1)
            if len(new_population) < TSP_POPULATION_SIZE:
                new_population.append(child2)
        
        population = new_population
    
    return best_route, best_distance

def display_tsp_solution(best_route, cities, selection_method):
    distance_val = total_distance(best_route, cities)
    fitness_val = 1.0 / distance_val if distance_val > 0 else 0
    
    print("\n--- TSP SOLUTION ---")
    print(f"Selection Method: {selection_method}")
    print(f"Best Route: {best_route}")
    print(f"Total Distance: {distance_val:.4f}")
    print(f"Fitness: {fitness_val:.6f}")

def main():
    print("=" * 50)
    print("GENETIC ALGORITHMS LAB")
    print("=" * 50)
    
    while True:
        print("\nChoose a task:")
        print("1. Knapsack Problem (GA)")
        print("2. Travelling Salesman Problem (GA)")
        print("3. Exit")
        
        choice = input("Enter your choice (1/2/3): ").strip()
        
        if choice == "1":
            items_list, max_weight = get_user_input()
            
            print("\nSelect selection method:")
            print("1. Roulette Wheel Selection")
            print("2. Tournament Selection")
            method_choice = input("Enter your choice (1/2): ").strip()
            
            if method_choice == "1":
                selection_method = "roulette"
            elif method_choice == "2":
                selection_method = "tournament"
            else:
                selection_method = "roulette"
            
            best_solution, best_fitness = genetic_algorithm(items_list, max_weight, selection_method)
            display_solution(best_solution, items_list, max_weight, selection_method)
        
        elif choice == "2":
            cities_dict = get_tsp_input()
            
            print("\nSelect selection method:")
            print("1. Roulette Wheel Selection")
            print("2. Tournament Selection")
            method_choice = input("Enter your choice (1/2): ").strip()
            
            if method_choice == "1":
                selection_method = "roulette"
            elif method_choice == "2":
                selection_method = "tournament"
            else:
                selection_method = "roulette"
            
            best_route, best_distance = tsp_genetic_algorithm(cities_dict, selection_method)
            display_tsp_solution(best_route, cities_dict, selection_method)
        
        elif choice == "3":
            print("Exiting...")
            break
        
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
