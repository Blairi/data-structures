import matplotlib.pyplot as plt

PATH = "/home/blairi/development/projects/data-structures"

def get_data(path:str) -> tuple[list[int], list[int]]:

    file = open(path, "r")

    ns = list()
    times = list()
    for line in file:

        line = line.rstrip()
        if line == "":
            continue

        n = line.split(":")[0]
        time = line.split(":")[1]

        ns.append( int(n) )
        times.append( int(time) )

    file.close()

    return ( ns, times )


def menu() -> None:
    title = ""
    data_structures = {"Queue": None, "Stack": None}
    while(True):
        print("Select the data structure operation by typing the number.")
        print("0. Exit")
        print("1. Access")
        print("2. Deletion")
        print("3. Search")
        print("4. Insertion")

        opc = input(": ")
        if not opc.isdigit() or ( opc.isdigit() and int(opc) not in range(0, 5) ):
            print("Illegal choice.")
            continue

        opc = int(opc)

        if opc == 0: # Exit
            break

        if opc == 1: # Access
            title = "Access"
            for data_structure in data_structures:
                data_structures[data_structure] = get_data(f"{PATH}/{data_structure}/data/access.txt")

        if opc == 2: # Deletion
            title = "Deletion"
            for data_structure in data_structures:
                data_structures[data_structure] = get_data(f"{PATH}/{data_structure}/data/deletion.txt")

        if opc == 3: # Search
            title = "Search"
            for data_structure in data_structures:
                data_structures[data_structure] = get_data(f"{PATH}/{data_structure}/data/search.txt")

        if opc == 4: # Insertion
            title = "Insertion"
            for data_structure in data_structures:
                data_structures[data_structure] = get_data(f"{PATH}/{data_structure}/data/insertion.txt")

        # Plotting
        cols = len(data_structures.keys())
        fig, axs = plt.subplots(nrows=1, ncols=cols)

        for i, key in enumerate(data_structures.keys()):
            axs[i].set_title(key)
            axs[i].grid(True)
            x, y = data_structures[key]
            axs[i].plot(x, y)

        for ax in axs.flat:
            ax.set(xlabel="Elements(n)", ylabel='Steps')

        plt.suptitle(title, fontsize=16)
        plt.show()


menu()
