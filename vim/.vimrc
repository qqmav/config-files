set t_Co=256
colorscheme ron

" Basic configuration
set nocompatible
syntax enable
filetype plugin indent on

" Cursorline
set cursorline
hi cursorline cterm=none ctermbg=237

" Statusline
set laststatus=2
set statusline=%<%f\ %h%m%r%=%-14.(%l,%c%V%)\ %P

" Search case
set ignorecase
set smartcase

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

set scrolloff=5
