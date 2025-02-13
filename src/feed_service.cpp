#include "feed_service.hpp"

feed_service::FeedHandler::FeedHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context)
: HttpHandlerBase(config, context),
    pg_cluster_(context.FindComponent<userver::components::Postgres>("database").GetCluster()) {}

std::string feed_service::FeedHandler::HandleRequest(
    userver::server::http::HttpRequest &request, 
    userver::server::request::RequestContext &) const
{
    return std::string("Hello world");
}
