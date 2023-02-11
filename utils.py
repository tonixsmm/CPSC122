# Name: Tony Nguyen
# Class: CPSC 122 01
# Date: February 10, 2022
# Programming Assignment: PA2
# Description: This program implements several sorting algorithm to compare for efficiency
# Note: I decided to use milliseconds instead of seconds for execution time measurement becuase it is more accurate
# Note: This utility file is adapted from my DA5 and DA6 submission, CPSC 222, Fall 2022, by Dr. Gina Sprint

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def data_loading(filename):
    data = pd.read_csv(filename)
    
    n = [500, 1000, 5000, 10000, 500, 1000, 5000, 10000, 500, 1000, 5000, 10000]
    n = pd.Series(n, name="Vector size")

    sort_type = ["Sorted", "Sorted", "Sorted", "Sorted", "Descending sorted", "Descending sorted", "Descending sorted", "Descending sorted", "Random", "Random", "Random", "Random"]
    sort_type = pd.Series(sort_type, name="Sort type")

    data = pd.concat([data, n], axis=1, ignore_index=False)
    data = pd.concat([data, sort_type], axis=1, ignore_index=False)
    
    data.set_index("Vector configuration", inplace=True)

    return data

def draw_plot(df_selection, df_bubble, df_insertion, df_shell, sort_type, graph_type):

    plt.figure(figsize=(10, 8))

    plt.plot([1, 2, 3, 4], df_selection[df_selection["Sort type"] == sort_type][graph_type],'o-', label="Selection")
    plt.plot([1, 2, 3, 4], df_bubble[df_bubble["Sort type"] == sort_type][graph_type],'v-', label="Bubble")
    plt.plot([1, 2, 3, 4], df_insertion[df_insertion["Sort type"] == sort_type][graph_type],'s-', label="Insertion")
    plt.plot([1, 2, 3, 4], df_shell[df_shell["Sort type"] == sort_type][graph_type],'*-', label="Shell")

    plt.xticks([1, 2, 3, 4], labels=[500, 1000, 5000, 10000])
    plt.xlabel("Vector Size N")

    if graph_type == "Milliseconds":
        plt.ylabel("Runnnig Time (ms)")
    if graph_type == "# Total":
        plt.ylabel("Total Operations")

    current_values = plt.gca().get_yticks()
    plt.gca().set_yticklabels(['{:,.0f}'.format(x) for x in current_values])

    plt.title(sort_type)
    plt.grid()
    plt.legend(title="Sorting Algorithms")

    plt.show()
