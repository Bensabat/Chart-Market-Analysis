import matplotlib.pyplot as plt
import numpy as np


def main():
    
    path = "formated-resources/CAC40_2018-05-14.txt"
    curve_list, times_list = parse_get_curve(path)

    curve_pattern_plot(curve_list, times_list)


def parse_get_curve(path):
    with open(path) as fp:

        # Parse each lines
        times_list = []
        curve_list = []
        for line in fp:
            line_split = line.split(" ")
            u = int(line_split[0])
            v = float(line_split[1].rstrip())

            times_list.append(u)
            curve_list.append(v)

    return curve_list, times_list


def curve_pattern_plot(curve_list, times_list):
    #curve_list = np.array([49, 13, 24, 24, 16, 14, 8, 18])
    #pattern_list = np.array([44, 11, 21, 20, 14, 13, 8, 16])

    #my_xticks = ['', '', '', '', '', '', '', '']

    plt.xticks(times_list, times_list, rotation=10)
    plt.plot(curve_list, label="Curve")
    #plt.plot(pattern_list, label="Pattern Founded")

    plt.legend(loc='upper right')
    plt.xlabel("Time")
    plt.ylabel("Value")
    plt.title("Pattern found on ")
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
      main()
