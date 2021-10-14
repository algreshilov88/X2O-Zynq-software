#!/usr/bin/python
"""
Original work Copyright (C) 2017 msilvaol (MIT License)
https://github.com/mvsoliveira/IBERTpy

Modified work Copyright (C) 2021 Aleksei Greshilov
aleksei.greshilov@cern.ch

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

"""
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
