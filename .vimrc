set number
let g:user42 = 'eslamber'
let g:mail42 = 'eslamber@student.42.fr'

nnoremap <F1> :Stdheader<CR>

set relativenumber

set autoindent
set tabstop=4
set shiftwidth=4
set smarttab
set softtabstop=4
set nowrap

set mouse=a

set colorcolumn=80

call plug#begin()

Plug '42Paris/42header'

call plug#end()
