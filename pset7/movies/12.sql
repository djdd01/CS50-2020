select title from movies
join ratings on movies.id = ratings.movie_id
join stars on ratings.movie_id = stars.movie_id
join people on person_id = people.id
where people.name in ("Johnny Depp", "Helena Bonham Carter")
group by title
having count(people.name) = 2;