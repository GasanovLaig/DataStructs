џў# p r a g m a   o n c e  
 # i n c l u d e   " B i n a r y T r e e N o d e . h "  
 # i n c l u d e   < i o s t r e a m >  
 # i n c l u d e   < s t r i n g >  
  
 t e m p l a t e   < c l a s s   T >  
 c l a s s   B i n a r y T r e e  
 {  
 p u b l i c :  
 	 ~ B i n a r y T r e e ( ) ;  
 	 v o i d   A d d ( T   d a t a )   {   A d d R e c u r s i v e ( _ r o o t ,   d a t a ) ;   }  
 	 v o i d   R e m o v e ( T   d a t a )   {   R e m o v e R e c u r s i v e ( _ r o o t ,   d a t a ) ;   }  
 	 c o n s t   B s t N o d e < T > *   F i n d ( T   d a t a )   {   r e t u r n   F i n d R e c u r s i v e ( _ r o o t ,   d a t a ) ;   }  
 	 c o n s t   B s t N o d e < T > *   F i n d M i n ( )   {   r e t u r n   F i n d M i n R e c u r s i v e ( _ r o o t ) ;   }  
 	 c o n s t   B s t N o d e < T > *   F i n d M a x ( )   {   r e t u r n   F i n d M a x R e c u r s i v e ( _ r o o t ) ;   }  
 	 v o i d   P r i n t ( )   {   P r i n t R e c u r s i v e ( _ r o o t ,   " " ,   f a l s e ) ;   }  
  
 p r i v a t e :  
 	 v o i d   D e s t r o y T r e e ( B s t N o d e < T > *   c u r r e n t ) ;  
 	 v o i d   A d d R e c u r s i v e ( B s t N o d e < T > * &   c u r r e n t ,   T   d a t a ) ;  
 	 v o i d   R e m o v e R e c u r s i v e ( B s t N o d e < T > * &   c u r r e n t ,   T   d a t a ) ;  
 	 c o n s t   B s t N o d e < T > *   F i n d R e c u r s i v e ( B s t N o d e < T > *   c u r r e n t ,   T   d a t a ) ;  
 	 B s t N o d e < T > * &   F i n d M i n R e c u r s i v e ( B s t N o d e < T > * &   c u r r e n t ) ;  
 	 B s t N o d e < T > * &   F i n d M a x R e c u r s i v e ( B s t N o d e < T > * &   c u r r e n t ) ;  
 	 v o i d   P r i n t R e c u r s i v e ( B s t N o d e < T > *   c u r r e n t ,   s t d : : s t r i n g   p r e f i x ,  
 	 	 b o o l   i s R i g h t ) ;  
  
 	 B s t N o d e < T > *   _ r o o t ;  
 } ;  
  
 t e m p l a t e   < c l a s s   T >  
 B i n a r y T r e e < T > : : ~ B i n a r y T r e e ( )  
 {  
 	 D e s t r o y T r e e ( _ r o o t ) ;  
 	 _ r o o t   =   n u l l p t r ;  
 }  
  
 t e m p l a t e   < c l a s s   T >  
 v o i d   B i n a r y T r e e < T > : : D e s t r o y T r e e ( B s t N o d e < T > *   c u r r e n t )  
 {  
 	 i f   ( c u r r e n t   = =   n u l l p t r )  
 	 {  
 	 	 r e t u r n ;  
 	 }  
  
 	 D e s t r o y T r e e ( c u r r e n t - > L e f t ) ;  
 	 D e s t r o y T r e e ( c u r r e n t - > R i g h t ) ;  
 	 d e l e t e   c u r r e n t ;  
 }  
  
 t e m p l a t e   < c l a s s   T >  
 v o i d   B i n a r y T r e e < T > : : A d d R e c u r s i v e ( B s t N o d e < T > * &   c u r r e n t ,   T   d a t a )  
 {  
 	 i f   ( c u r r e n t   = =   n u l l p t r )  
 	 {  
 	 	 c u r r e n t   =   n e w   B s t N o d e < T > {   n u l l p t r ,   n u l l p t r ,   d a t a   } ;  
 	 	 r e t u r n ;  
 	 }  
 	  
 	 i f   ( d a t a   = =   c u r r e n t - > D a t a )  
 	 {  
 	 	 r e t u r n ;  
 	 }  
 	 e l s e   i f   ( d a t a   <   c u r r e n t - > D a t a )  
 	 {  
 	 	 A d d R e c u r s i v e ( c u r r e n t - > L e f t ,   d a t a ) ;  
 	 }  
 	 e l s e  
 	 {  
 	 	 A d d R e c u r s i v e ( c u r r e n t - > R i g h t ,   d a t a ) ;  
 	 }  
 }  
  
 t e m p l a t e   < c l a s s   T >  
 v o i d   B i n a r y T r e e < T > : : R e m o v e R e c u r s i v e ( B s t N o d e < T > * &   c u r r e n t ,   T   d a t a )  
 {  
 	 i f   ( c u r r e n t   = =   n u l l p t r )  
 	 {  
 	 	 r e t u r n ;  
 	 }  
 	  
 	 i f   ( d a t a   = =   c u r r e n t - > D a t a )  
 	 {  
 	 	 B s t N o d e < T > *   n e w S u c c e s s o r   =   n u l l p t r ;  
 	 	 i f   ( c u r r e n t - > L e f t   ! =   n u l l p t r   & &   c u r r e n t - > R i g h t   ! =   n u l l p t r )  
 	 	 {  
 	 	 	 B s t N o d e < T > * &   s u c c e s s o r   =   F i n d M i n R e c u r s i v e ( c u r r e n t - > R i g h t ) ;  
 	 	 	 c u r r e n t - > D a t a   =   s u c c e s s o r - > D a t a ;  
 	 	 	 R e m o v e R e c u r s i v e ( s u c c e s s o r ,   s u c c e s s o r - > D a t a ) ;  
 	 	 	 r e t u r n ;  
 	 	 }  
 	 	 e l s e   i f   ( c u r r e n t - > L e f t   ! =   n u l l p t r )  
 	 	 {  
 	 	 	 n e w S u c c e s s o r   =   c u r r e n t - > L e f t ;  
 	 	 }  
 	 	 e l s e   i f   ( c u r r e n t - > R i g h t   ! =   n u l l p t r )  
 	 	 {  
 	 	 	 n e w S u c c e s s o r   =   c u r r e n t - > R i g h t ;  
 	 	 }  
 	 	 d e l e t e   c u r r e n t ;  
 	 	 c u r r e n t   =   n e w S u c c e s s o r ;  
 	 }  
 	 e l s e   i f   ( d a t a   <   c u r r e n t - > D a t a )  
 	 {  
 	 	 R e m o v e R e c u r s i v e ( c u r r e n t - > L e f t ,   d a t a ) ;  
 	 }  
 	 e l s e  
 	 {  
 	 	 R e m o v e R e c u r s i v e ( c u r r e n t - > R i g h t ,   d a t a ) ;  
 	 }  
 }  
  
 t e m p l a t e   < c l a s s   T >  
 c o n s t   B s t N o d e < T > *   B i n a r y T r e e < T > : : F i n d R e c u r s i v e ( B s t N o d e < T > *   c u r r e n t ,   T   d a t a )  
 {  
 	 i f   ( c u r r e n t   = =   n u l l p t r )  
 	 {  
 	 	 r e t u r n   n u l l p t r ;  
 	 }  
 	  
 	 i f   ( d a t a   = =   c u r r e n t - > D a t a )  
 	 {  
 	 	 r e t u r n   c u r r e n t ;  
 	 }  
 	 e l s e   i f   ( d a t a   <   c u r r e n t - > D a t a )  
 	 {  
 	 	 r e t u r n   F i n d R e c u r s i v e ( c u r r e n t - > L e f t ,   d a t a ) ;  
 	 }  
 	 e l s e  
 	 {  
 	 	 r e t u r n   F i n d R e c u r s i v e ( c u r r e n t - > R i g h t ,   d a t a ) ;  
 	 }  
 }  
  
 t e m p l a t e   < c l a s s   T >  
 B s t N o d e < T > * &   B i n a r y T r e e < T > : : F i n d M i n R e c u r s i v e ( B s t N o d e < T > * &   c u r r e n t )  
 {  
 	 i f   ( c u r r e n t - > L e f t   = =   n u l l p t r )  
 	 {  
 	 	 r e t u r n   c u r r e n t ;  
 	 }  
 	 r e t u r n   F i n d M i n R e c u r s i v e ( c u r r e n t - > L e f t ) ;  
 }  
  
 t e m p l a t e   < c l a s s   T >  
 B s t N o d e < T > * &   B i n a r y T r e e < T > : : F i n d M a x R e c u r s i v e ( B s t N o d e < T > * &   c u r r e n t )  
 {  
 	 i f   ( c u r r e n t - > R i g h t   ! =   n u l l p t r )  
 	 {  
 	 	 r e t u r n   c u r r e n t ;  
 	 }  
 	 r e t u r n   F i n d M a x R e c u r s i v e ( c u r r e n t - > L e f t ) ;  
 }  
  
 t e m p l a t e   < c l a s s   T >  
 v o i d   B i n a r y T r e e < T > : : P r i n t R e c u r s i v e ( B s t N o d e < T > *   c u r r e n t ,  
 	 s t d : : s t r i n g   p r e f i x ,   b o o l   i s R i g h t )  
 {  
 	 i f   ( c u r r e n t   ! =   n u l l p t r )  
 	 {  
 	 	 s t d : : c o u t   < <   p r e f i x ;  
 	 	 s t d : : c o u t   < <   " | _ _ _ _ _ " ;  
 	 	 s t d : : c o u t   < <   c u r r e n t - > D a t a   < <   ' \ n ' ;  
  
 	 	 P r i n t R e c u r s i v e ( c u r r e n t - > R i g h t ,  
 	 	 	 p r e f i x   +   ( i s R i g h t   ?   " |           "   :   "           " ) ,   t r u e ) ;  
 	 	 P r i n t R e c u r s i v e ( c u r r e n t - > L e f t ,  
 	 	 	 p r e f i x   +   ( i s R i g h t   ?   " |           "   :   "           " ) ,   f a l s e ) ;  
 	 }  
 } 