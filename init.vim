set number
set relativenumber
syntax on
set mouse=a

set autoindent
set tabstop=4
set shiftwidth=4
set smarttab
set softtabstop=4
set nowrap

set nohlsearch " no highlight search
set incsearch
set noerrorbells

set scrolloff=8

set colorcolumn=80
set signcolumn=yes
set encoding=UTF-8

" ------- Plugins --------
call plug#begin()
" 42
Plug '42Paris/42header'

" Finder
Plug 'nvim-lua/plenary.nvim'
Plug 'BurntSushi/ripgrep'
Plug 'nvim-telescope/telescope.nvim'

Plug 'https://github.com/preservim/nerdtree' " NerdTree
Plug 'https://github.com/vim-airline/vim-airline' " Status bar

Plug 'http://github.com/tpope/vim-surround' " Surrounding ysw)
Plug 'https://github.com/tpope/vim-commentary' " For Commenting gcc & gc
Plug 'https://github.com/lifepillar/pgsql.vim' " PSQL Pluging needs :SQLSetType pgsql.vim
" Plug 'https://github.com/neoclide/coc.nvim'  " Auto Completion

Plug 'https://github.com/ryanoasis/vim-devicons' " Developer Icons
Plug 'https://github.com/tc50cal/vim-terminal' " Vim Terminal
Plug 'https://github.com/preservim/tagbar' " Tagbar for code navigation
" Plug 'https://github.com/terryma/vim-multiple-cursors' " CTRL + N for multiple cursors

" Color themes
Plug 'gruvbox-community/gruvbox'

call plug#end()

"let ayucolor="mirage"
colorscheme gruvbox

set termguicolors
set background=dark
highlight Normal guibg=none

nnoremap <C-f> :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
"nnoremap <C-l> :call CocActionAsync('jumpDefinition')<CR>

nmap <F8> :TagbarToggle<CR>

set completeopt-=preview " For No Previews

" Find files using Telescope command-line sugar.
nnoremap <leader>ff <cmd>Telescope find_files<cr>
nnoremap <leader>fg <cmd>Telescope live_grep<cr>
nnoremap <leader>fb <cmd>Telescope buffers<cr>
nnoremap <leader>fh <cmd>Telescope help_tags<cr>

let g:NERDTreeDirArrowExpandable="+"
	let g:NERDTreeDirArrowCollapsible="~"

" --- Just Some Notes ---
"  " :PlugClean :PlugInstall :UpdateRemotePlugins
"  "
"  " :CocInstall coc-python
"  " :CocInstall coc-clangd
"  " :CocInstall coc-snippets
"  " :CocCommand snippets.edit... FOR EACH FILE TYPE
"
" air-line
let g:airline_powerline_fonts = 1
"
"  if !exists('g:airline_symbols')
"      let g:airline_symbols = {}
"      endif
"
"      " airline symbols
"      let g:airline_left_sep = ''
"      let g:airline_left_alt_sep = ''
"      let g:airline_right_sep = ''
"      let g:airline_right_alt_sep = ''
"      let g:airline_symbols.branch = ''
"      let g:airline_symbols.readonly = ''

"--- 42 HEADER ---
let g:user42 = "eslamber"
let g:mail42 = "eslamber@student.42.ft"

nnoremap <F1> :Stdheader<CR>
