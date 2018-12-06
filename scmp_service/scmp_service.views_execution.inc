<?php

/**
 * @file
 * Views execution file.
 */

use Drupal\views\ViewExecutable;
use Drupal\views\Plugin\views\query\QueryPluginBase;

/**
 * Implements hook_views_query_alter().
 */
function scmp_service_views_query_alter(ViewExecutable $view, QueryPluginBase $query) {
  $params = \Drupal::request()->query->all();
  if ($view->id() == 'article_feed' && $view->current_display == 'date_range') {
    $from_date = $params['fromDate'];
    $to_date = $params['toDate'];
    foreach ($query->where[1]['conditions'] as $key => $value) {
      if ($key == 2 && $value['field'] == 'node__field_publication_date.field_publication_date_value') {
        $query->where[1]['conditions'][$key]['value'] = $from_date;
      }
      if ($key == 3 && $value['field'] == 'node__field_publication_date.field_publication_date_value') {
        $query->where[1]['conditions'][$key]['value'] = $to_date;
      }
    }
  }
  if ($view->id() == 'article_feed' && $view->current_display == 'in_date') {
    $date = $params['date'];
    $date = strtotime(date('Y-m-d', $date));
    foreach ($query->where[1]['conditions'] as $key => $value) {
      if ($key == 2 && $value['field'] == 'node__field_publication_date.field_publication_date_value') {
        $query->where[1]['conditions'][$key]['value'] = $date;
      }
      if ($key == 3 && $value['field'] == 'node__field_publication_date.field_publication_date_value') {
        $query->where[1]['conditions'][$key]['value'] = $date + 86400;
      }
    }
  }
  if ($view->id() == 'article_feed' && $view->current_display == 'topics') {
    $limit = isset($params['limit']) ? $params['limit'] : 1;
    $query->setLimit($limit);
  }
}
