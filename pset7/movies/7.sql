select title, rating from
movies join ratings on id = movie_id
where year = 2010
order by rating desc, title asc
LIMIT 10;