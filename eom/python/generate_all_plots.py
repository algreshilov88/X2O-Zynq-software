#!/usr/bin/python

from eyescan_plot import eyescan_plot
from eyescan_plot import get_eye
from glob import glob
import os.path
import csv

overwrite = True

filename_i_list = glob('../scans/csv/*')
filename_o_list = [p.replace('csv','png') for p in filename_i_list]

yticks = range(0, 64, 3)
xticks = range(0, 64, 3)

k=1

for i,o in zip(filename_i_list, filename_o_list):
    print('Saving file {0:03d} out of {1:d}.'.format(k,len(filename_i_list)))

    if (not os.path.exists(o)) or overwrite:
            eyescan_plot(i, o, xaxis=True, yaxis=True, xticks_f=xticks, yticks_f=yticks)

    k += 1
    #break
