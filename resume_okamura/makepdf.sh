#!/bin/bash

platex resume_pdf.tex
platex resume_pdf.tex
dvipdfmx resume_pdf.dvi
