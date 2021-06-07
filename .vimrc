" Basic configuration
set nocompatible
syntax enable
filetype plugin indent on

" Fuzzy finding
set path+=**
set wildmenu

" 2-wide tabs, always, expanded to spaces
set tabstop=2
set softtabstop=2
set shiftwidth=2
set expandtab

" Tags
command! MakeTags !ctags -R .

" Use hybrid numbering scheme, where the current line is the absolute number
" and the rest are relative numbers
set number
set relativenumber
