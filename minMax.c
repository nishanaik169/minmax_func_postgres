#include "postgres.h"
#include "fmgr.h"
#include "utils/geo_decls.h"
#include "utils/elog.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(minMax_sfunc);

Datum
minMax_sfunc(PG_FUNCTION_ARGS)
{
        Point *minMaxResult = (Point *) palloc(sizeof(Point));
        Point *minMax_new_agg = (Point *) palloc(sizeof(Point));
        double el = PG_GETARG_INT32(1);
        Point *pointx = PG_GETARG_POINT_P(0);

bool isnull = PG_ARGISNULL(0);
        if(isnull) {
                minMax_new_agg->x = el;
                minMax_new_agg->y = el;
                PG_RETURN_POINT_P(minMax_new_agg);
        }

        minMax_new_agg->x = el;


   if(minMax_new_agg->x < pointx->x) {
                minMaxResult->x = minMax_new_agg->x;
        } else {
                minMaxResult->x = pointx->x;
        }

   if(minMax_new_agg->x > pointx->y) {
                minMaxResult->y = minMax_new_agg->x;
        } else {
                minMaxResult->y = pointx->y;
        }
PG_RETURN_POINT_P(minMaxResult);
}
