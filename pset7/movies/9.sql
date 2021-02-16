select DISTINCT(name) from
people join stars on people.id = person_id
join movies on movie_id = movies.id
where year = 2004 
order by birth asc;