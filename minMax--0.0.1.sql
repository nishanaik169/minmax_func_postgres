drop aggregate if exists minMax(int);
drop function if exists minMax_finalfunc(point);
drop function if exists minMax_sfunc(point,point);

create function
  minMax_sfunc( point,int)
returns
  point
as
  'minMax.so', 'minMax_sfunc'
language c
immutable;

create function minMax_finalfunc(agg_state point)
returns record
immutable
language plpgsql
as $$
DECLARE 
ret record;
begin
  select agg_state[0] || '->' ||  agg_state[1] into ret;
  return ret;
end;
$$;

create aggregate minMax(int)
(
    sfunc = minMax_sfunc,
    stype = point,
    finalfunc = minMax_finalfunc
);
