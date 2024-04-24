#!/bin/bash

platex resume_ps.tex
platex resume_ps.tex
dvips resume_ps.dvi -o resume.ps
