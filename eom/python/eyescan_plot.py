import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import csv
import operator as op
from matplotlib.colors import ListedColormap
import matplotlib.pylab as pl
import matplotlib as mpl
from matplotlib.path import Path
import matplotlib.patches as patches
import os

# list split
def chunkify(items, chunk_size):
    for i in range(0, len(items), chunk_size):
        yield items[i:i+chunk_size]

# function for getting eye data
def get_eye(scan_list):
    eyedata = False
    yticks = []
    img = []
    image = []
    date = "N/A"
    time = "N/A"
    n = 0
    k = 0
    s = 64

    for row in scan_list:
        if row[0].startswith('Date and Time Started'):
            dt = row[1]
            date = dt.split(' ')[0]
            time = dt.split(' ')[1]

        if row[0].startswith('Scan Name'):
            header = row[1]

        if row[0].startswith('Scan End'):
            eyedata = False

        if eyedata:
            yticks.append(row[0])
            img.append(row[1:])

        if row[0].startswith('2d statistical'):
            xticks = row[1:]
            eyedata = True

    while n < 64:
        for elem in img:
            image.append(elem[n])
        n += 1
    
    image = chunkify(image, 64)

    img = [[float(y) for y in x] for x in image]
    xticks = [int(x) for x in xticks]
    yticks = [int(y) for y in yticks]

    return [img, xticks, yticks, date, time]


#Generate eyescan plots
def eyescan_plot(filename_i, filename_o, xaxis=True, yaxis=True, xticks_f=[],yticks_f=[]):

    # opens the file
    with open(filename_i, 'rb') as f:
            reader = csv.reader(f)
            scan_list = list(reader)


    # getting eye data
    [img, xticks, yticks, date, time] = get_eye(scan_list)

    # function for calculating x-y axis ranges in a such way that ticks is in the center of each entry
    def get_extent(xticks_n,yticks_r):
        xmin = xticks_n[0]
        xmax = xticks_n[-1]
        xstep = (xmax-xmin)/(len(xticks_n)-1)
        xmin_e = xmin-xstep/2
        xmax_e = xmax+xstep/2
        ymin = yticks_r[0]
        ymax = yticks_r[-1]
        ystep = (ymax-ymin)/(len(yticks_r)-1)
        ymin_e = ymin-ystep/2
        ymax_e = ymax+ystep/2
        return [xmin_e, xmax_e, ymin_e, ymax_e]

    fig, ax = plt.subplots(num=None, figsize=(10, 7), dpi=80, facecolor='w', edgecolor='k')
    xticks_n = [x for x in xticks]
    yticks_r = [y for y in yticks]

    myplot = plt.imshow(img,interpolation='none', aspect='auto', extent = get_extent(xticks_n,yticks_r), cmap = 'jet')
    if xaxis:
         if not yticks:
              plt.xticks(xticks_n)
         else:
              plt.xticks(xticks_f)
    if yaxis:
         if not yticks:
              plt.yticks(yticks_r)
         else:
              plt.yticks(yticks_f)
    else:
         plt.yticks([])

    title = "Eye Opening Monitor" + "\n\n" + "Date: " + date + ", Time: " + time + "\n"

    # formating colorbar axis
    plt.title(title)
    plt.xlabel("Phase Position")
    plt.ylabel("Voltage Position")

    # saving plot
    #plt.savefig(filename_o,bbox_inches='tight')
    # showing plot if needed
    plt.show()
    plt.close()
